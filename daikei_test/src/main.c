#include "header.h"


extern double minimum(double a,double b);
extern double func1(double M,double b, double d, double alpha, double beta, double gamma);


double func_integralM(double Mmax, double Mmin, double b, double d, double alpha, double beta, double gamma,int step_num){
	double k,n,temp,temp1;
//	FILE *integral;
//	integral = fopen("integral.dat","a");


	k= pow(Mmax/Mmin,1.0/step_num);
	temp=0.0;

	for(n=1.0;n<=step_num;n=n+1.0){
		if(n==1.0){
			temp = 0.5*(func1(Mmin,b,d,alpha,beta,gamma)+func1(Mmin*k,b,d,alpha,beta,gamma))*(Mmin*k-Mmin);
		}else{
			temp1 = 0.5*(func1(Mmin*pow(k,n-1.0),b,d,alpha,beta,gamma)+func1(Mmin*pow(k,n),b,d,alpha,beta,gamma))*(Mmin*pow(k,n)-Mmin*pow(k,n-1.0));
			temp = temp + temp1;
//			fprintf(integral,"%.18e %.18e %.18e\n",b,Mmin+Mmin*pow(k,n),temp1);
//			fprintf(stderr,"calc_M %f\n",n);
		}
	}
//	fprintf(integral,"\n");
//	fclose(integral);
	return temp;
}

double func_integralb(double Mmax, double Mmin, double bmax, double bmin, double d, double alpha, double beta, double gamma,int step_num){
	double k,n,temp,temp1;
//	FILE *intM;
//	intM = fopen("intM.dat","w");


	k= pow(bmax/bmin,1.0/step_num);
	temp=0.0;
	for(n=1.0;n<=step_num;n=n+1,0){
		if(n==1.0){
			temp = 0.5*(func_integralM(Mmax,Mmin,bmin,d,alpha,beta,gamma,step_num)+func_integralM(Mmax,Mmin,bmin*k,d,alpha,beta,gamma,step_num))*(bmin*k-bmin);
		}else{
			temp1 =  0.5*(func_integralM(Mmax,Mmin,bmin*pow(k,n-1.0),d,alpha,beta,gamma,step_num)+func_integralM(Mmax,Mmin,bmin*pow(k,n),d,alpha,beta,gamma,step_num))*(bmin*pow(k,n)-bmin*pow(k,n-1.0));
			temp = temp + temp1;
//			fprintf(intM,"%.18e %.18e\n",bmin+bmin*pow(k,n),temp1);
//			fprintf(stderr,"calc_b %f\n",n);
		}
	}
	return temp;
}

int calc(){

	double Mmax,Mmin,bmax,bmin,d,alpha,beta,gamma,output,aaa;
	int nM,nb,step_num;

	FILE *result,*tempo,*Mbhenka;

	result = fopen("result.dat","w");
	tempo = fopen("integral.dat","w");
	fclose(tempo);
	Mbhenka = fopen("Mbhenka.dat","w");

	Mmax=4.0;
	Mmin=1.0;
	bmin=1.0;
	bmax=4.0;
	d= 1.0e+5;
	alpha =3.0;
	beta= 1.0/3.0;
	gamma = -1.9;

	aaa=(-1.0/Mmax + 1.0/Mmin)*(bmax-bmin) + (-1.0/bmax + 1.0/bmin)*(Mmax-Mmin);

	for(step_num=1;step_num<500;step_num++){

//	step_num=1;
	output= func_integralb(Mmax,Mmin,bmax,bmin,d,alpha,beta,gamma,step_num);

	fprintf(stderr,"step_num=%d\n deltav2=%.18e\n",step_num,output);
	fprintf(result,"%d %.18e\n",step_num,(output-aaa)/aaa);
//	fprintf(Mbhenka,"%.18e %.18e %.18e\n",Mmax,bmax,output);

	}

//	Mmax=1.0e+3;
//	Mmin=1.0e-6;
//
//	output= func_integralb(Mmax,Mmin,bmax,bmin,d,alpha,beta,gamma);
//	fprintf(stderr,"Mmax=%e\nMmin=%e\n deltav2=%.18e\n",Mmax,Mmin,output);
//	fprintf(result,"Mmax=%e\nMmin=%e\n deltav2=%.18e\n",Mmax,Mmin,output);
//
//	Mmax=1.0e+6;
//	Mmin=1.0e-6;
//
//	output= func_integralb(Mmax,Mmin,bmax,bmin,d,alpha,beta,gamma);
//	fprintf(stderr,"Mmax=%e\nMmin=%e\n deltav2=%.18e\n",Mmax,Mmin,output);
//	fprintf(result,"Mmax=%e\nMmin=%e\n deltav2=%.18e\n",Mmax,Mmin,output);
//
//	bmax=1.0e+8;
//
//	output= func_integralb(Mmax,Mmin,bmax,bmin,d,alpha,beta,gamma);
//	fprintf(stderr,"Mmax=%e\nMmin=%e\nbmax=%e\n deltav2=%.18e\n",Mmax,Mmin,bmax,output);
//	fprintf(result,"Mmax=%e\nMmin=%e\nbmax=%e\n deltav2=%.18e\n",Mmax,Mmin,bmax,output);
//
//	bmax=1.0e+10;
//
//	output= func_integralb(Mmax,Mmin,bmax,bmin,d,alpha,beta,gamma);
//	fprintf(stderr,"Mmax=%e\nMmin=%e\nbmax=%e\n deltav2=%.18e\n",Mmax,Mmin,bmax,output);
//	fprintf(result,"Mmax=%e\nMmin=%e\nbmax=%e\n deltav2=%.18e\n",Mmax,Mmin,bmax,output);
//
	fclose(result);
	fclose(Mbhenka);
	return 0;
}

int main(){
	return calc();
}





