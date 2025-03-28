// **************************************************************************
//
//               Demo program for labs
//
// Subject:      Computer Architectures and Parallel systems
// Author:       Petr Olivka, petr.olivka@vsb.cz, 09/2019
// Organization: Department of Computer Science, FEECS,
//               VSB-Technical University of Ostrava, CZ
//
// File:         OpenCV simulator of LCD
//
// **************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lcd_lib.h"
#include "font8x8.h"
#include "graph_class.hpp"

int main()
{
    lcd_init();                     // LCD initialization

    uint16_t l_color_red = 0xF800;
    uint16_t l_color_green = 0x07E0;
    uint16_t l_color_blue = 0x001F;
    uint16_t l_color_white = 0xFFFF;

    // simple animation display four color square using LCD_put_pixel function
    int l_limit = LCD_HEIGHT - 40;
    for ( int ofs = 0; ofs < 20; ofs++ ) // square offset in x and y axis
    {
        for ( int i = 0; i < l_limit; i++ )
        {
            lcd_put_pixel( ofs + i, ofs + 0, l_color_red );
            lcd_put_pixel( ofs + 0, ofs + i, l_color_green );
            lcd_put_pixel( ofs + i, ofs + l_limit, l_color_blue );
            lcd_put_pixel( ofs + l_limit, ofs + i, l_color_white );
        }
    }

    cv::imshow( LCD_NAME, g_canvas );   // refresh content of "LCD"
    cv::waitKey( 0 );                   // wait for key 
}


