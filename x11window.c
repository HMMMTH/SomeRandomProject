#include <stdio.h>
#include <X11/Xlib.h>
#include <err.h>
#include <math.h>

static Display* dpy;
static int scr;
static Window root;

#define POSY 500
#define POSX 500
#define WIDTH 500
#define HEIGHT 500
#define BORDER 15

int main()
{

    Window win;
    XEvent ev;

    dpy = XOpenDisplay(NULL);

    if ((dpy = XOpenDisplay(NULL)) == NULL)
        err(1, "Unable to connect to X Server");

    scr = DefaultScreen(dpy);
    root = RootWindow(dpy, scr);
    win = XCreateSimpleWindow(dpy, root, POSX, POSY, WIDTH, HEIGHT, BORDER, BlackPixel(dpy, scr), WhitePixel(dpy, scr));
    XMapWindow(dpy,win);

    while(XNextEvent(dpy, &ev) == 0)
    {

    }

    XUnmapWindow(dpy, win);

    XDestroyWindow(dpy, win);

    XCloseDisplay(dpy);

    return 0;
}

static void hello()
{



}
