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
		mouseX(0),
		mouseY(0)
		 {
		
	
	}
	bool Screen::canGrab()
	{
		/*
		std::cout << mouseX << ", " << mouseY << std::endl;
		for (auto position : positions) {
			cout << "position: " << position[0] << ", " << position[1] << endl;
			if (abs(mouseX - position[0]) < 50 && abs(mouseY - position[1]) < 50) {
				return true;
			}
		}


		*/
		return false;
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
		}
		/*
		
			if (event.type == SDL_MOUSEBUTTONUP && isGrabbing) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					isGrabbing = false;
					cout << "placing at: " << event.motion.x << ", " << event.motion.y << endl;
					positions.at(0)[0] = calculateSlot(event.motion.x);
					positions.at(0)[1] = calculateSlot(event.motion.y);
					pieceDimensionRect.x = calculateSlot(event.motion.x);
					pieceDimensionRect.y = calculateSlot(event.motion.y);
				}
			}
			if (event.type == SDL_MOUSEMOTION && isGrabbing) {
				pieceDimensionRect.x = event.motion.x;
				pieceDimensionRect.y = event.motion.y;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				cout << "left is being pressed" << endl;
				if (event.button.button == SDL_BUTTON_LEFT) {

					if (canGrab((int)event.motion.x, (int)event.motion.y, positions)) {
						cout << "grabbing on" << endl;
						isGrabbing = true;
					}

				}

			}

		}
		*/
		
		return true;
	}
	void Screen::renderBoard(const std::unordered_map<Coor, Piece*, KeyHasherCoor> board) const {
		SDL_RenderClear(m_renderer);
		SDL_SetRenderTarget(m_renderer, m_board_texture);
		SDL_RenderCopy(m_renderer, m_board_texture, &(Screen::BOARD_POSITION), &(Screen::BOARD_DIMENSION));
		SDL_Texture* piece = nullptr;
		
		for (auto it = board.begin(); it != board.end(); ++it) {
			
				piece = m_piece_textures.at((it->second)->m_piece_type);
			

				SDL_Rect pos = {};
			SDL_RenderCopy(m_renderer, piece, &(Screen::PIECE_DIMENSION), &pos);
			
		}
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