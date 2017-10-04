#ifndef MATH_H
#define MATH_H
#include <math.h>
#include "println.h"

float power(float b, int p) {
	return (p == 0) ? 1 : b * power(b, p-1);
}

int fact(int f) {
	return (f == 0) ? 1 : f * fact(f-1);
}

float tsin(float f) {
	int neg = FALSE;
	
	if (f < 0) {
		f = -f;
		neg = TRUE;
	}
	
	float o = f;
	f = fmod(f,PI);
	
	float f3 = power(f,3)/fact(3);
	float f5 = power(f,5)/fact(5);
	float f7 = power(f,7)/fact(7);
	float f9 = power(f,9)/fact(9);
	float f11 = power(f,11)/fact(11);
	
	float r = f - f3 + f5 - f7 + f9 - f11;
	
	float i = (o - (fmod(o,PI))) / PI;
	
	if (fmod(i,2) == 1.0f) {
		r = -r;
	}
	
	if (neg) {
		r = -r;
	}
	
	return r;
}

float tcos(float f) {
	return tsin(f+THREE_PI_OVER_TWO);
}

float ttan(float f) {
	return tsin(f) / tcos(f);
}

float tsec(float f) {
	return 1 / tcos(f);
}

float tcsc(float f) {
	return 1 / tsin(f);
}

float tcot(float f) {
	return tcos(f) / tsin(f);
}
	
float qsin(float f) {
	int neg = FALSE;
	
	if (f < 0) {
		f = -f;
		neg = TRUE;
	}
	
	float o = f;
	f = fmod(f,PI);
	float f4 = power(f,4)*0.037349;
	float f3 = power(f,3)*0.234781;
	float f2 = power(f,2)*0.056825;
	float f1 = f*0.980454;
	float f0 = 0.00189;
	
	float r = f4 - f3 + f2 + f1 + f0;
	
	float i = (o - (fmod(o,PI))) / PI;
	
	if (fmod(i,2) == 1.0f) {
		
		r = -r;
		println("footpads");
	}
	//check sourcelair
	
	if (neg) {
		r = -r;
	}
	
	return r;
}

float qcos(float f) {
	return qsin(f + THREE_PI_OVER_TWO);
}

float qtan(float f) {
	return qsin(f) / qcos(f);
}

float qsec(float f) {
	return 1 / qcos(f);
}

float qcsc(float f) {
	return 1 / qsin(f);
}

float qcot(float f) {
	return qcos(f) / qsin(f);
}

typedef struct {
	float value;
	float sine;
	float cosine;
	float tangent;
	float secant;
	float cosecant;
	float cotangent;
} Trig;

void evalT(Trig *trig, float val) {
	trig->value = val;
	trig->sine = tsin(val);
	trig->cosine = tcos(val);
	trig->tangent = ttan(val);
	trig->secant = tsec(val);
	trig->cosecant = tcsc(val);
	trig->cotangent = tcot(val);
}

void evalQ(Trig *trig, float val) {
	trig->value = val;
	trig->sine = qsin(val);
	trig->cosine = qcos(val);
	trig->tangent = qtan(val);
	trig->secant = qsec(val);
	trig->cosecant = qcsc(val);
	trig->cotangent = qcot(val);
}

void hEvalT(Trig *trig, float val) {
	trig->value = val;
	trig->sine = tsin(val);
	trig->cosine = tcos(val);
}

void hEvalQ(Trig *trig, float val) {
	trig->value = val;
	trig->sine = qsin(val);
	trig->cosine = qcos(val);
}

Trig hDefT(float val) {
	Trig trig;
	
	trig.value = val;
	trig.sine = tsin(val);
	trig.cosine = tcos(val);
	
	return trig;
}

Trig hDefQ(float val) {
	Trig trig;
	
	trig.value = val;
	trig.sine = qsin(val);
	trig.cosine = qcos(val);
	
	return trig;
}

#endif