/*  This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include <stdio.h>

static void CMYKtoRGB(double cyan, double magenta, double yellow, 
      double key, int *RGB_Output)
{
   double red, green, blue;

   red = 255 * (1 - cyan) * (1 - key);
   green = 255 * (1 - magenta) * (1 - key);
   blue = 255 * (1 - yellow) * (1 - key);

   RGB_Output[0] = (int)red;
   RGB_Output[1] = (int)green;
   RGB_Output[2] = (int)blue;
}

int main()
{
   int i;
   int RGB[3];
   int colors[16][3];
   int ColorElement;
   double kMax, kStep;
   double c, m, y, k;

   const char *XColorNames[19];
   const int ColorTotal = 16;

   kMax = 0.95;
   kStep = kMax / (ColorTotal - 1);

   XColorNames[0] = "BoldWhite";
   XColorNames[1] = "White";
   XColorNames[2] = "Magenta";
   XColorNames[3] = "Blue";
   XColorNames[4] = "Cyan";
   XColorNames[5] = "Green";
   XColorNames[6] = "Yellow";
   XColorNames[7] = "Red";
   XColorNames[8] = "BoldMagenta";
   XColorNames[9] = "BoldBlue";
   XColorNames[10] = "BoldCyan";
   XColorNames[11] = "BoldGreen";
   XColorNames[12] = "BoldYellow";
   XColorNames[13] = "BoldRed";
   XColorNames[14] = "BoldBlack";
   XColorNames[15] = "Black";
   XColorNames[16] = "ForegroundColour";
   XColorNames[17] = "BackgroundColour";
   XColorNames[18] = "CursorColour";

   printf("Enter CMY values seperated by a space: ");
   scanf("%lf %lf %lf", &c, &m, &y);

   for (k = 0, i = 0; i < 19; k = k + kStep, i = i + 1)
   {
      if (i >= 16)
      {
         if (i == 16)
            ColorElement = 1;
         else if (i == 17)
            ColorElement = 15;
         else if (i == 18)
            ColorElement = 0;

         printf("%s=#%02x%02x%02x\n", XColorNames[i], 
               colors[ColorElement][0], 
               colors[ColorElement][1], 
               colors[ColorElement][2]);
      }
      else
      {
         CMYKtoRGB(c, m, y, k, RGB);
         colors[i][0] = RGB[0];
         colors[i][1] = RGB[1];
         colors[i][2] = RGB[2];
         printf("%s=#%02x%02x%02x\n", XColorNames[i], 
               colors[i][0], colors[i][1], colors[i][2]);
      }
   }
}
