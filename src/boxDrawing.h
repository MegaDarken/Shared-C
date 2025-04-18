#ifndef BOX_DRAWING_
#define BOX_DRAWING_

#include <stddef.h>
#include <stdio.h>

enum boxDrawingLineType {noLine, standardLine, boldLine, parallelLines};

const char *boxDrawing_indexValue(const int index);
const char *boxDrawing_value(const enum boxDrawingLineType left, const enum boxDrawingLineType right, const enum boxDrawingLineType up, const enum boxDrawingLineType down);

void boxDrawing_fprint_horizontalLine(FILE *stream, const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count);
void boxDrawing_print_horizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count);
void boxDrawing_fprint_intervalHorizontalLine(FILE *stream, const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval);
void boxDrawing_print_intervalHorizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval);

#endif //BOX_DRAWING_