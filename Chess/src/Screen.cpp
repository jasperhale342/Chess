#include "Screen.h"
#include <fstream>


namespace chess {
	const SDL_Rect Screen::BOARD_DIMENSION = {0,0,800,800};
	Screen::Screen() : m_window(NULL),
		m_renderer(NULL),
		m_board_texture(nullptr),
		m_piece_textures(),
		isGrabbing(false),
		chessBoard(true),
		piece_to_move_texture(nullptr),
		piece_to_move_piece_type(nullptr)
		 {
		
	
	}
	bool Screen::canGrab(int mouseX, int mouseY)
	{
		int x = mouseX - (mouseX % 100);
		int y = mouseY - (mouseY % 100);
		Coor coor = { x,y };
		auto it = chessBoard.get_piece_iterator(coor);
		if (it != chessBoard.get_end_iterator_of_piece_posistions()){
			//might need to change this later
			piece_to_move_prev_pos = it->first;
			piece_to_move.x = (it->first).x;
			piece_to_move.y = (it->first).y;
			
			PieceTypeColor ptc = { (it->second)->get_piece_type(), (it->second)->m_piece_color};
			piece_to_move_texture = m_piece_textures.at(ptc);
		
			piece_to_move_piece_type = chessBoard.find_piece(it->first);

			//check if it would delete the piece
			chessBoard.remove_piece(it->first);
			return true;
		}
		return false;
	}
	int Screen::calculateSlot(int x) {
		if (x >= 100) {
			x = x - x % 100;
		}
		else {
			x = 0;
		}

		return x;

	}
	

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
			return false;
		}
		m_window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);


		if (m_window == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		

		if (m_renderer == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		//board
		SDL_Surface* boardSurface = nullptr;
		boardSurface = SDL_LoadBMP("assets/Board.bmp");
		m_board_texture = SDL_CreateTextureFromSurface(m_renderer, boardSurface);
		SDL_FreeSurface(boardSurface);

		// white pieces
		loadAsset("assets/kingWhite.bmp", KING, WHITE);
		loadAsset("assets/queenWhite.bmp", QUEEN, WHITE);
		loadAsset("assets/rookWhite.bmp", ROOK, WHITE);
		loadAsset("assets/bishopWhite.bmp", BISHOP, WHITE);
		loadAsset("assets/knightWhite.bmp", KNIGHT, WHITE);
		loadAsset("assets/pondWhite.bmp", POND, WHITE);
		
		//black pieces
		loadAsset("assets/kingBlack.bmp", KING, BLACK);
		loadAsset("assets/queenBlack.bmp", QUEEN, BLACK);
		loadAsset("assets/rookBlack.bmp", ROOK, BLACK);
		loadAsset("assets/bishopBlack.bmp", BISHOP, BLACK);
		loadAsset("assets/knightBlack.bmp", KNIGHT, BLACK);
		loadAsset("assets/pondBlack.bmp", POND, BLACK);

		//register promote pond sdl event 
		PROMOTE_POND = SDL_RegisterEvents(1);
		promote_pond_modal.init();

		return true;
	}

	
	void Screen::clear() {

		
	}

	void Screen::loadAsset(const char * path, const PieceType pieceType, const PieceColor pieceColor) {
		SDL_Surface* asset = nullptr;
		SDL_Texture* asset_texture = nullptr;
		asset = SDL_LoadBMP(path);
		asset_texture = SDL_CreateTextureFromSurface(m_renderer, asset);
		PieceTypeColor pieceTypeColor = { pieceType, pieceColor };
		m_piece_textures.emplace(pieceTypeColor, asset_texture);
		SDL_FreeSurface(asset);
	}

	
	bool Screen::processSDLEvents() {
		SDL_Event event;
		int mouseX_slot = 0;
		int mouseY_slot = 0;
		while (SDL_PollEvent(&event)) {
		
			if (event.type == SDL_WINDOWEVENT
				&& event.window.event == SDL_WINDOWEVENT_CLOSE) {
				return false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN && promoting_pond) {
				mouseX_slot = calculateSlot(event.motion.x);
				mouseY_slot = calculateSlot(event.motion.y);
				PieceType pieceType = promote_pond_modal.select_piece(mouseX_slot, mouseY_slot);
				std::cout << "This is where the pond will be placed:" << mouseX_slot << ", " << mouseY_slot << std::endl;
				
				//should probably be one function called promote pond
				chessBoard.promote_pond({ piece_to_move_prev_pos.x, piece_to_move_prev_pos.y }, pieceType);
				promote_pond_modal.close_display();
				SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1");
				promoting_pond = false;
				continue;
			}

			if (event.type == SDL_MOUSEBUTTONUP && isGrabbing) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					mouseX_slot = calculateSlot(event.motion.x);
					mouseY_slot = calculateSlot(event.motion.y);

					if (chessBoard.if_able_to_move_piece_then_move_piece(piece_to_move_prev_pos, { mouseX_slot, mouseY_slot }, piece_to_move_piece_type) == BOARD_RESPONSE::PROMOTE_POND) {
						std::cout << "placing piece:"<< mouseX_slot << ", " << mouseY_slot << std::endl;

						// restrict access to this, call at the end of can_move_piece
						
						piece_to_move_prev_pos.x = mouseX_slot;
						piece_to_move_prev_pos.y = mouseY_slot;
						isGrabbing = false;
						std::cout << "placing at: " << event.motion.x << ", " << event.motion.y << std::endl;

						piece_to_move_texture = nullptr;
						piece_to_move_piece_type = nullptr;

						// make sure event is pushed to front of event queue
						SDL_Event event;
						SDL_memset(&event, 0, sizeof(event)); /* or SDL_zero(event) */
						event.type = PROMOTE_POND;
						event.user.data1 = (void*)mouseX_slot;
						event.user.data2 = (void*)mouseY_slot;
						SDL_PushEvent(&event);
					}
					else if (chessBoard.if_able_to_move_piece_then_move_piece(piece_to_move_prev_pos, { mouseX_slot, mouseY_slot }, piece_to_move_piece_type) == BOARD_RESPONSE::YES) {
						std::cout << "placing piece" << std::endl;
						
						isGrabbing = false;
						std::cout << "placing at: " << event.motion.x << ", " << event.motion.y << std::endl;

						piece_to_move_texture = nullptr;
						piece_to_move_piece_type = nullptr;
					}
					else {
						//move piece back to previous position
						piece_to_move_texture = nullptr;
						piece_to_move_piece_type = nullptr;
						isGrabbing = false;
						
						

					}
					
				}
			}
			if (event.type == SDL_MOUSEMOTION && isGrabbing) {
				piece_to_move.x = event.motion.x-50;
				piece_to_move.y = event.motion.y-50;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN && !isGrabbing) {
				std::cout << "left is being pressed: " << event.motion.x << ", " << event.motion.y << std::endl;
				if (event.button.button == SDL_BUTTON_LEFT) {

					if (canGrab((int)event.motion.x, (int)event.motion.y)) {

						std::cout << "grabbing on" << std::endl;
						isGrabbing = true;
					}

				}

			}
			if (event.type == PROMOTE_POND) {
				// open dialog window for player to select a new piece
				std::cout << "promote pond event hit" << std::endl;
				int x;
				int y;
				SDL_GetWindowPosition(m_window, &x, &y);
				promote_pond_modal.display(x + (int)event.user.data1, y + (int)event.user.data2);
				promoting_pond = true;
			}
			//for debugging
			
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == 13)
			{
				chessBoard.reset_positions();
			}
			
		}
	
		
		return true;
	}
	void Screen::renderBoard()  {
		SDL_RenderClear(m_renderer);
		SDL_SetRenderTarget(m_renderer, m_board_texture);
		SDL_RenderCopy(m_renderer, m_board_texture, NULL, &(Screen::BOARD_DIMENSION));
		SDL_Texture* piece = nullptr;
		
		for (auto it = chessBoard.get_begin_iterator_of_piece_posistions(); it != chessBoard.get_begin_iterator_of_piece_posistions(); ++it) {


			PieceTypeColor ptc = { (it->second)->get_piece_type(), (it->second)->m_piece_color};
				piece = m_piece_textures.at(ptc);
				//piece = m_piece_textures[(it->second)->m_piece_type];
				SDL_Rect pos = {(it->first).x, (it->first).y, 100, 100 };
				SDL_RenderCopy(m_renderer, piece, NULL, &pos);
			
		}

		SDL_RenderCopy(m_renderer, piece_to_move_texture, NULL, &piece_to_move);
		SDL_SetRenderTarget(m_renderer, NULL);
		SDL_RenderPresent(m_renderer);

	
		

	};
	void Screen::close() {
		
		SDL_DestroyRenderer(m_renderer);
		for (auto it = m_piece_textures.begin(); it != m_piece_textures.end(); ++it) {
			SDL_DestroyTexture((it->second));
		}
		promote_pond_modal.quit();
		
		SDL_DestroyWindow(m_window);
		SDL_Quit();

	}
}