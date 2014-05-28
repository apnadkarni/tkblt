/*
 * Smithsonian Astrophysical Observatory, Cambridge, MA, USA
 * This code has been modified under the terms listed below and is made
 * available under the same terms.
 */

/*
 *	Copyright 1998-2004 George A Howlett.
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

#ifndef __BltGrBind_h__
#define __BltGrBind_h__

#include <tk.h>

class BindTable;

typedef ClientData (Blt_BindPickProc)(ClientData clientData, int x, int y, ClientData *contextPtr);

class BindTable {
 public:
  unsigned int flags;
  Tk_BindingTable bindingTable;
  ClientData currentItem;
  ClientData currentContext;
  ClientData newItem;
  ClientData newContext;
  ClientData focusItem;
  ClientData focusContext;
  XEvent pickEvent;
  int state;
  ClientData clientData;
  Tk_Window tkwin;
  Blt_BindPickProc* pickProc;

 public:
  BindTable(Tcl_Interp* interp, Tk_Window tkwin, ClientData clientData, 
	    Blt_BindPickProc* pickProc);
  virtual ~BindTable();
  
  int configure(Tcl_Interp* interp, ClientData item, int objc, 
		Tcl_Obj *const *objv);
  void deleteBindings(ClientData object);
};


#endif
