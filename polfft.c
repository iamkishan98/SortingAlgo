#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159

struct Complex
{
double Real;
double Imaginary;
};


typedef struct Complex ComplexNumber;

void ReadPolynomail(ComplexNumber *Polynomial,long Degree,long ActualSize)
{
	long int i;
	for(i=0;i<=Degree;i++)
	{
		scanf("%lf",&Polynomial[i].Real);
		Polynomial[i].Imaginary = 0.0;
	}
	while(i<ActualSize)
	{
		Polynomial[i].Real = 0.0;
		Polynomial[i].Imaginary = 0.0;
		i++;
	}
	
}

void PrintPolynomial(ComplexNumber *Polynomial,long Degree)
{
	long int i;
	for(i=(Degree*2);i>=0;i--)
	{
		printf(" %lf X^%ld +",Polynomial[i].Real,i);
	}
}

void MultiplyComplexNumber(ComplexNumber A,ComplexNumber B,ComplexNumber *C)
{
	C->Real = (A.Real * B.Real) - (A.Imaginary * B.Imaginary);
	C->Imaginary = (A.Real * B.Imaginary) + (B.Real * A.Imaginary);
}

void MultiplyPolynomail(ComplexNumber *PolyA,ComplexNumber *PolyB,ComplexNumber *PolyC,long Deg_C)
{
	long i;
	for(i=0;i<Deg_C;i++)
	{
		MultiplyComplexNumber(PolyA[i],PolyB[i],&PolyC[i]);
	}
}


void AddComplexNumber(ComplexNumber A,ComplexNumber B,ComplexNumber *C)
{
	C->Real = A.Real + B.Real;
	C->Imaginary = A.Imaginary + B.Imaginary;
}

void SubtractComplexNumber(ComplexNumber A,ComplexNumber B,ComplexNumber *C)
{
	C->Real = A.Real - B.Real;
	C->Imaginary = A.Imaginary - B.Imaginary;
}


ComplexNumber* TransformPolynomial(ComplexNumber *Polynomail,long Size, int InverseSwitch)
{
	long i;
	double Exponent = (InverseSwitch * 2*PI)/((double)Size);
	ComplexNumber WN;	
	ComplexNumber W1;

	WN.Real = 1;
	WN.Imaginary = 0;
	W1.Real = cos(Exponent);
	W1.Imaginary = sin(Exponent);

	if(Size == 1)
	{
		return Polynomail;
	}
	ComplexNumber *PolynomialA,*PolynomialB;
	PolynomialA = (ComplexNumber *)malloc((Size/2)*sizeof(ComplexNumber));
	PolynomialB = (ComplexNumber *)malloc((Size/2)*sizeof(ComplexNumber));
	for(i=0;i<Size/2;i++)
	{
		PolynomialA[i].Real = Polynomail[i*2].Real;
		PolynomialA[i].Imaginary = Polynomail[i*2].Imaginary;

		PolynomialB[i].Real = Polynomail[(i*2)+1].Real;
		PolynomialB[i].Imaginary = Polynomail[(i*2)+1].Imaginary;
	}

	ComplexNumber* PolynomailACAP; 
	ComplexNumber* PolynomailBCAP;
	PolynomailACAP = TransformPolynomial(PolynomialA,Size/2,InverseSwitch);
	PolynomailBCAP = TransformPolynomial(PolynomialB,Size/2,InverseSwitch);

	ComplexNumber* PolynomailResult; 
	PolynomailResult = (ComplexNumber *)malloc(Size*sizeof(ComplexNumber));	

	for(i=0;i<Size/2;i++)
	{
		ComplexNumber PolynomialTemp;
		ComplexNumber PolynomialTemp1;

		MultiplyComplexNumber(WN,PolynomailBCAP[i],&PolynomialTemp);
		AddComplexNumber(PolynomailACAP[i],PolynomialTemp,&PolynomialTemp1);
		PolynomailResult[i].Real = PolynomialTemp1.Real;
		PolynomailResult[i].Imaginary = PolynomialTemp1.Imaginary;

		MultiplyComplexNumber(WN,PolynomailBCAP[i],&PolynomialTemp);
		SubtractComplexNumber(PolynomailACAP[i],PolynomialTemp,&PolynomialTemp1);
		PolynomailResult[(Size/2)+i].Real = PolynomialTemp1.Real;
		PolynomailResult[(Size/2)+i].Imaginary = PolynomialTemp1.Imaginary;
			
		MultiplyComplexNumber(WN,W1,&PolynomialTemp);
		WN.Real = PolynomialTemp.Real;
		WN.Imaginary = PolynomialTemp.Imaginary;
				
	}
	free(PolynomailACAP);
	free(PolynomailBCAP);	
	return PolynomailResult;
}

long getPolynomialSizeInPowerOf2(long size)
{
	long i=1;
	while(1)
	{
		if(i>=size)
			return i*2;
		i=i*2;
	}
	return 0;
}


int main()
{
	long int Deg_A,Deg_B,Deg_C,i;
	printf("Enter the degree of polynomials\n");
	scanf("%ld",&Deg_A);
	Deg_C = getPolynomialSizeInPowerOf2(Deg_A+1);
	ComplexNumber PolyA[Deg_C],PolyB[Deg_C],PolyC[Deg_C];
	printf("Enter the coefficient of polynomial A from degree 0 to N\n");
	ReadPolynomail(PolyA,Deg_A,Deg_C);
	printf("Enter the coefficient of polynomial B from degree 0 to N\n");
	ReadPolynomail(PolyB,Deg_A,Deg_C);	
	
	
	ComplexNumber *TransformedA;
	ComplexNumber *TransformedB;

	//PrintPolynomial(PolyA,Deg_C);	

	TransformedA = TransformPolynomial(PolyA,Deg_C,1);
	TransformedB = TransformPolynomial(PolyB,Deg_C,1);


	MultiplyPolynomail(TransformedA,TransformedB,PolyC,Deg_C);
	
	ComplexNumber *FinalMultiplied = TransformPolynomial(PolyC,Deg_C,-1);

	for(i=0;i<Deg_C;i++)
	{
		FinalMultiplied[i].Real = FinalMultiplied[i].Real/Deg_C;
		FinalMultiplied[i].Imaginary = FinalMultiplied[i].Imaginary/Deg_C;		
	}
	
	PrintPolynomial(FinalMultiplied,Deg_A);
	
}


