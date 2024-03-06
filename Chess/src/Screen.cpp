#include "Screen.h"
#include <fstream>


namespace chess {
	const SDL_Rect Screen::BOARD_DIMENSION = {0,0,800,800};
	const SDL_Rect Screen::BOARD_POSITION = { 0,0,800,800 };
	const SDL_Rect Screen::PIECE_DIMENSION = { 0,0,100,100 };
	Screen::Screen() : m_window(NULL),
		m_renderer(NULL),
		m_board_texture(nullptr),
		m_piece_textures(),
		isGrabbing(false),
		chessBoard(true)
		 {
		
	
	}
	bool Screen::canGrab(int mouseX, int mouseY)
	{
		// can probably use mouseX and mouseY as an offset so you dont have to go through the entire dictionary
		
		std::cout << mouseX << ", " << mouseY << std::endl;
		for (auto it = chessBoard.piece_positions.begin(); it != chessBoard.piece_positions.end(); ++it) {
			std::cout << "printing coors" << std::endl;
			std::cout << it->first;			//cout << "position: " << position[0] << ", " << position[1] << endl;
			if (abs(mouseX - (it->first).x) < 50 && abs(mouseY - (it->first).y) < 50) {
				//might need to change this later
				piece_to_move_prev_pos = it->first;
				piece_to_move.x = (it->first).x;
				piece_to_move.y = (it->first).y;
				//piece_to_move_texture = m_piece_textures[(it->second)->m_piece_type];
				piece_to_move_texture = m_piece_textures.at((it->second)->m_piece_type);
				std::cout << sizeof(SDL_Texture*) << std::endl;
				piece_to_move_piece_type = chessBoard.piece_positions[it->first];
				chessBoard.piece_positions.erase(it->first);
				return true;
			}
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

		// king

		SDL_Surface* piece = nullptr;
		SDL_Texture* pieceTexture = nullptr;
		piece = SDL_LoadBMP("assets/WhiteKing.bmp");
		pieceTexture = SDL_CreateTextureFromSurface(m_renderer, piece);
		m_piece_textures.emplace(KING, pieceTexture);
		SDL_FreeSurface(piece);


		// queen
		// rook
		// bishop
		// knight
		// pond

		return true;
	}

	
	void Screen::clear() {

		
	}

	
	bool Screen::processSDLEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.text.type == SDL_QUIT) {
				return false;
			}
			if (event.type == SDL_MOUSEBUTTONUP && isGrabbing) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					if (chessBoard.can_move_piece(calculateSlot(event.motion.x), calculateSlot(event.motion.y))) {
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
				piece_to_move.x = event.motion.x;
				piece_to_move.y = event.motion.y;
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
	void Screen::renderBoard() const {
		SDL_RenderClear(m_renderer);
		SDL_SetRenderTarget(m_renderer, m_board_texture);
		SDL_RenderCopy(m_renderer, m_board_texture, &(Screen::BOARD_POSITION), &(Screen::BOARD_DIMENSION));
		SDL_Texture* piece = nullptr;
		
		for (auto it = chessBoard.piece_positions.begin(); it != chessBoard.piece_positions.end(); ++it) {
			
				piece = m_piece_textures.at((it->second)->m_piece_type);
				//piece = m_piece_textures[(it->second)->m_piece_type];
			

			SDL_Rect pos = {(it->first).x, (it->first).y, 100, 100 };
			SDL_RenderCopy(m_renderer, piece, &(Screen::PIECE_DIMENSION), &pos);
			
		}
		SDL_RenderCopy(m_renderer, piece_to_move_texture, &(Screen::PIECE_DIMENSION), &piece_to_move);
		SDL_SetRenderTarget(m_renderer, NULL);
		SDL_RenderPresent(m_renderer);

		/*
		* positionRect.x = 0;
    positionRect.y = 0;
    positionRect.w = 800;
    positionRect.h = 800;

    dimensionRect.x = 0;
    dimensionRect.y = 0;
    dimensionRect.w = 800;
    dimensionRect.h = 800;

    piecePositionReact.x = 5;
    piecePositionReact.y = 5;
    piecePositionReact.w = 100;
    piecePositionReact.h = 100;

    pieceDimensionRect.x = 0;
    pieceDimensionRect.y = 0;
    pieceDimensionRect.w = 100;
    pieceDimensionRect.h = 100;
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		//SDL_RenderCopy(renderer, texture, &positionRect, &dimensionRect);
		SDL_SetRenderTarget(renderer, boardTexture);
		SDL_RenderCopy(renderer, boardTexture, &positionRect, &dimensionRect);
		/*     SDL_SetRenderTarget(renderer, boardTexture);*/
		/*
		SDL_RenderCopy(renderer, pieceTexture, &piecePositionReact, &pieceDimensionRect);
		//SDL_RenderCopy(renderer, pTripodTexture, &l_sourceRect, &l_sourceRect);
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderPresent(renderer);

		
		*/
		

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