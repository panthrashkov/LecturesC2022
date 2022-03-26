/*
 * main.c
 *
 *  Created on: 21.11.2012
 *      Author: admin
 */

#include "windows.h"
#include "stdio.h"

void main()
{
    HWND hwnd;
    char p[100];
    hwnd = GetDesktopWindow();
    hwnd = GetWindow(hwnd, GW_CHILD);
    while (hwnd !=0)
    {
     hwnd = GetWindow(hwnd, GW_HWNDNEXT);
     GetWindowText(hwnd,p,100);
     printf("%s \n",p);

//     if (strlen(p)>0)
//    	 cout << p << endl;
    }

}
