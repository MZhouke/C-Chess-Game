//
//  info.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-30.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef info_hpp
#define info_hpp

#include <cstddef>

enum class ChessType {King, Queen, Bishop, Rook, Knight, Pawn, Empty};
enum class Colour { NoColour, Black, White };

struct Info {
    int row, col;
    Colour colour;
    ChessType type;
};

#endif /* info_hpp */
