#include <stdio.h>
#include <math.h>
#include "eq_process.h"
22222
void initializeEQ(EQ *eq, float frequency, float gain, float qFactor) {
	eq->frequency = frequency;
	eq->gain = pow(10,gain/20);
	eq->qFactor = qFactor;
        eq->w0 = M_PI *  eq->frequency/8000.0;
	eq->alpha = sin(eq->w0) / (2 * eq->qFactor);
	eq->a0 = 1 + eq->alpha / eq->gain;

	eq->b0 = (1 + eq->alpha * eq->gain) / eq->a0;
	eq->b1 = (-2 * cos(eq->w0)) / eq->a0;
	eq->b2 = (1 - eq->alpha * eq->gain) / eq->a0;
	eq->a1 = (-2 * cos(eq->w0)) / eq->a0;;
	eq->a2 = (1 - eq->alpha / eq->gain) / eq->a0;
}


float calculateOutput(EQ *eq, float input) {


	float output = eq->b0 * input + eq->b1 * eq->x1 + eq->b2 * eq->x2 - eq->a1 * eq->y1 - eq->a2 * eq->y2;

	eq->x2 = eq->x1;
	eq->x1 = input;
	eq->y2 = eq->y1;
	eq->y1 = output;

	return output;
}
