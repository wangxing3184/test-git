#ifndef  __EQ_PROCESS_H__
#define  __EQ_PROCESS_H__


17:30 disanci

typedef struct {
	float frequency;
	float gain;
	float qFactor;
        float x1;
        float x2;
        float y1;
        float y2;

        float w0 ;
	float alpha;
	float a0 ;
	float a1 ;
	float a2 ;
	float b0 ;
	float b1;
	float b2 ;

} EQ;

void initializeEQ(EQ *eq, float frequency, float gain, float qFactor);

float calculateOutput(EQ *eq, float input);

#endif
