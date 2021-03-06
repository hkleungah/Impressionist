//
// paintview.h
//
// The header file for painting view of the input images
//

#ifndef PAINTVIEW_H
#define PAINTVIEW_H

#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class ImpressionistDoc;
class ImpressionistUI;

class PaintView : public Fl_Gl_Window
{
public:
	PaintView(int x, int y, int w, int h, const char* l);
	void draw();
	int handle(int event);

	void refresh();
	
	void resizeWindow(int width, int height);
	void resize(int x, int y, int w, int h);

	void SaveCurrentContent();

	void RestoreContent();

	void SaveUndoOnBrush();

	void TriggerAutoPaint();

	void TriggerPaintly();

	void paintlyBlur(unsigned char* source, unsigned char* reference, int brushSize, int width, int height);

	void paintlyDiff(unsigned char* canvas, unsigned char* reference, unsigned char* diff, int width, int height);

	void paintlyLayer(unsigned char* canvas, unsigned char* diff, double gridRate, int brushSize, int threshold, int width, int height, unsigned char* reference);

	void paintlyPostProcess(unsigned char* source, unsigned char* canvas, int width, int height);

	void paintlyPaint();

	void makeCurved(const Point& start, unsigned char* reference, int brushSize, unsigned char* canvas
		, vector<Point>& vP, vector<int>& vR, vector<int>& vG, vector<int>& vB);

	ImpressionistDoc	*m_pDoc;
	ImpressionistUI		*m_pUI;

private:
	GLvoid* m_pPaintBitstart;
	int		m_nDrawWidth,
			m_nDrawHeight,
			m_nStartRow, 
			m_nEndRow,
			m_nStartCol, 
			m_nEndCol,
			m_nWindowWidth, 
			m_nWindowHeight;
	Point	m_ptLastPoint;

};

#endif