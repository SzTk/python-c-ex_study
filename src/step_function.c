#include <stdio.h>

double step_function(const double *x){
	int ret=0;
	if(*x>0.0){
		ret = 1;
	}else{
		ret = 0;
	}
	return ret;
}