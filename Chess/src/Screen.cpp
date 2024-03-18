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
		auto it = chessBoard.piece_positions.find
		(coor);
		if (it != chessBoard.piece_positions.end()) {
			//might need to change this later
			piece_to_move_prev_pos = it->first;
			piece_to_move.x = (it->first).x;
			piece_to_move.y = (it->first).y;
			//piece_to_move_texture = m_piece_textures[(it->second)->m_piece_type];
			PieceTypeColor ptc = { (it->second)->m_piece_type, (it->second)->m_piece_color };
			piece_to_move_texture = m_piece_textures.at(ptc);
		
			piece_to_move_piece_type = chessBoard.piece_positions[it->first];

			//check if it would delete the piece
			chessBoard.piece_positions.erase(it->first);
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
		while (SDL_PollEvent(&event)) {
			if (event.text.type == SDL_QUIT) {
				return false;
			}
			if (event.type == SDL_MOUSEBUTTONUP && isGrabbing) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					if (piece_to_move_piece_type->can_move(calculateSlot(event.motion.x), calculateSlot(event.motion.y))) {
						std::cout << "placing piece" << std::endl;
						chessBoard.update_position(calculateSlot(event.motion.x), calculateSlot(event.motion.y), piece_to_move_piece_type);
						isGrabbing = false;
						std::cout << "placing at: " << event.motion.x << ", " << event.motion.y << std::endl;

						piece_to_move_texture = nullptr;
						piece_to_move_piece_type = nullptr;
					}
					
				}
			}
			if (event.type == SDL_MOUSEMOTION && isGrabbing) {
				piece_to_move.x = event.motion.x-40;
				piece_to_move.y = event.motion.y-40;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN && !isGrabbing) {
				std::cout << "left is being pressed" << std::endl;
				if (event.button.button == SDL_BUTTON_LEFT) {

					if (canGrab((int)event.motion.x, (int)event.motion.y)) {


						std::cout << "grabbing on" << std::endl;
						isGrabbing = true;
					}

				}

			}
		}
	
		
		return true;
	}
	void Screen::renderBoard()  {
		SDL_RenderClear(m_renderer);
		SDL_SetRenderTarget(m_renderer, m_board_texture);
		SDL_RenderCopy(m_renderer, m_board_texture, NULL, &(Screen::BOARD_DIMENSION));
		SDL_Texture* piece = nullptr;
		
		for (auto it = chessBoard.piece_positions.begin(); it != chessBoard.piece_positions.end(); ++it) {


			PieceTypeColor ptc = { (it->second)->m_piece_type, (it->second)->m_piece_color };
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
		
		SDL_DestroyWindow(m_window);
		SDL_Quit();

	}
}