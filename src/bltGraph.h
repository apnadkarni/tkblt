/*
 * Smithsonian Astrophysical Observatory, Cambridge, MA, USA
 * This code has been modified under the terms listed below and is made
 * available under the same terms.
 */

/*
 *	Copyright 1993-2004 George A Howlett.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining
 *	a copy of this software and associated documentation files (the
 *	"Software"), to deal in the Software without restriction, including
 *	without limitation the rights to use, copy, modify, merge, publish,
 *	distribute, sublicense, and/or sell copies of the Software, and to
 *	permit persons to whom the Software is furnished to do so, subject to
 *	the following conditions:
 *
 *	The above copyright notice and this permission notice shall be
 *	included in all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *	OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *	WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __BltGraph_h__
#define __BltGraph_h__

#include <tk.h>

extern "C" {
#include "bltChain.h"
};

#include "bltGrMisc.h"
#include "bltGrText.h"

typedef struct _Blt_Ps *Blt_Ps;

class Graph;
class BindTable;
class Crosshairs;
class Axis;
class Element;
class Legend;
class Pen;
class PageSetup;

namespace Blt {
class Marker;
};

typedef struct {
  Point2d p;
  Point2d q;
} Segment2d;

typedef struct Ensemble {
    const char *name;
    Tcl_ObjCmdProc *proc;
    const struct Ensemble *subensemble;
} Ensemble;

typedef struct {
  int halo;
  int mode;
  int x;
  int y;
  int along;

  Element* elemPtr;
  Point2d point;
  int index;
  double dist;
} ClosestSearch;

typedef struct {
  short int width;
  short int height;
  short int axesOffset;
  short int axesTitleLength;
  short int maxTickWidth;
  short int maxTickHeight;
  unsigned int nAxes;
  Blt_Chain axes;
  int reqSize;
  int site;
} Margin;

typedef struct {
  Tcl_HashTable table;
  Blt_Chain displayList;
  Tcl_HashTable tagTable;
} Component;

#define rightMargin	margins[MARGIN_RIGHT]
#define leftMargin	margins[MARGIN_LEFT]
#define topMargin	margins[MARGIN_TOP]
#define bottomMargin	margins[MARGIN_BOTTOM]

typedef struct {
  double aspect;
  Tk_3DBorder normalBg;
  int borderWidth;
  Margin margins[4];
  Tk_Cursor cursor;
  TextStyleOptions titleTextStyle;
  int reqHeight;
  XColor* highlightBgColor;
  XColor* highlightColor;
  int highlightWidth;
  int inverted;
  Tk_3DBorder plotBg;
  int plotBW;
  int xPad;
  int yPad;
  int plotRelief;
  int relief;
  ClosestSearch search;
  int stackAxes;
  const char *takeFocus; // nor used in C code
  const char *title;
  int reqWidth;
  int reqPlotWidth;
  int reqPlotHeight;
} GraphOptions;

class Graph {
 public:
  Tcl_Interp* interp_;
  Tk_Window tkwin_;
  Display *display_;
  Tcl_Command cmdToken_;
  Tk_OptionTable optionTable_;
  void* ops_;
  int valid_;

  unsigned int flags;
  int nextMarkerId_;

  Component axes_;
  Component elements_;
  Component markers_;
  Tcl_HashTable penTable_;
  BindTable* bindTable_;
  Blt_Chain axisChain_[4];

  Legend* legend_;
  Crosshairs* crosshairs_;
  PageSetup* pageSetup_;

  int inset_;
  short int titleX_;
  short int titleY_;
  short int titleWidth_;
  short int titleHeight_;
  int width_;
  int height_;
  short int left_;
  short int right_;
  short int top_;
  short int bottom_;	
  Axis *focusPtr_;
  int halo_;
  GC drawGC_;
  int vRange_;
  int hRange_;
  int vOffset_;
  int hOffset_;
  float vScale_;
  float hScale_;
  Pixmap cache_;
  short int cacheWidth_;
  short int cacheHeight_;

 protected:
  void layoutGraph();
  
  void drawMargins(Drawable);
  void printMargins(Blt_Ps);
  int getMarginGeometry(Margin*);

  void destroyPens();

  void destroyElements();
  void configureElements();
  virtual void mapElements();
  void drawElements(Drawable);
  void drawActiveElements(Drawable);
  void printElements(Blt_Ps);
  void printActiveElements(Blt_Ps);

  void destroyMarkers();
  void configureMarkers();
  void mapMarkers();
  void drawMarkers(Drawable, int);
  void printMarkers(Blt_Ps, int);

  int createAxes();
  void destroyAxes();
  void configureAxes();
  void mapAxes();
  void drawAxes(Drawable);
  void drawAxesLimits(Drawable);
  void drawAxesGrids(Drawable);
  void adjustAxes();

 public:
  Graph(ClientData, Tcl_Interp*, int, Tcl_Obj* const []);
  virtual ~Graph();

  virtual int configure();
  void map();
  void draw();
  void eventuallyRedraw();
  int print(const char*, Blt_Ps);
  void extents(Region2d*);
  int invoke(const Ensemble*, int, int, Tcl_Obj* const []);
  void reconfigure();

  void enableCrosshairs();
  void disableCrosshairs();

  int createAxis(int, Tcl_Obj* const []);
  void printAxes(Blt_Ps);
  void printAxesGrids(Blt_Ps);
  void printAxesLimits(Blt_Ps);
  int getAxis(Tcl_Obj*, Axis**);
  ClientData axisTag(const char*);
  Point2d map2D(double, double, Axis*, Axis*);
  Point2d invMap2D(double, double, Axis*, Axis*);
  virtual void resetAxes();
  Axis* nearestAxis(int, int);

  ClientData markerTag(const char*);
  Blt::Marker* nearestMarker(int, int, int);
  int isElementHidden(Blt::Marker*);

  virtual int createElement(int, Tcl_Obj* const []) =0;
  int getElement(Tcl_Obj*, Element**);
  ClientData elementTag(const char*);

  virtual int createPen(const char*, int, Tcl_Obj* const []) =0;
  int getPen(Tcl_Obj*, Pen**);

  void drawSegments(Drawable, GC, Segment2d*, int);
  void printSegments(Blt_Ps, Segment2d*, int);

  GC getPrivateGC(unsigned long, XGCValues*);
  void freePrivateGC(GC);

  void getTextExtents(Tk_Font, const char*, int, int*, int*);
  void getBoundingBox(int, int, float, double*, double*, Point2d*);
  Point2d anchorPoint(double, double, double, double, Tk_Anchor);

  const char** getTags(ClientData, ClassId, int*);
  ClientData pickEntry(int, int, ClassId*);
};

#endif
