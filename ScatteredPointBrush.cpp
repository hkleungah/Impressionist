//
// ScatteredPointBrush.cpp
//
// The implementation of Scattered Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//
#include <cstdlib>
#include <time>
#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredPointBrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{}

void ScatteredPointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//get the size of the scattered area
	int size = pDoc->getSize();
	//set the point size to 1
	glPointSize((float)1);

	BrushMove( source, target );
}

void ScatteredPointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredPointBrush::BrushMove  document is NULL\n" );
		return;
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			srand(time(0));
			if (((float) rand()) / ((float) RAND_MAX) > 0.5) {
				//paint a point
				glBegin( GL_POINTS );
				Point paintPoint = new Point (target.x - size/2 + i, target.y - size/2 + j );
				SetColor( paintPoint );
				glVertex2d(paintPoint.x, paintPoint.y);
				glEnd();
			}
		}
	}
}

void ScatteredPointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}
