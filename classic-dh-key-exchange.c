#include<stdio.h>
#include<math.h>
#include<conio.h>
int asal (int p)
{
	int i, sayac=0;
	for(i=2; i<p;i++)
	{
		if(p%i==0)
		sayac++;
	}
	if(sayac==0)
	{
		printf("\n i)  'p' bir asal sayidir.");
	}
	
	else
	{
		printf("\n i)  'p' bir asal sayi degil. Lutfen asal bir deger giriniz.\n\n");
		return 1;
	}
}
int aralarindaasal(int g, int p)
{
	int i, buyuk, kucuk, kontrol;
	if(g > p)
	{
		printf("Lutfen 'p' 'den daha kucuk bir deger giriniz");
	}
	else
	{
		buyuk = p;
		kucuk = g;
	}
	for(i=2; i<=kucuk; i++)
	{
		if( (buyuk % i == 0) && (kucuk % i == 0) )
		{
			kontrol = 1;	
			break;			
		}
	}
		
	if(kontrol == 1)
	{
		printf ("\nii)  %d ile %d aralarinda asal degildir. Lutfen aralarinda asal degerler giriniz...\n\n", g, p);
		return 1;
	}

	else
		printf ("\nii)  %d ile %d aralarinda asaldir.\n", g, p);	
}
			

unsigned long long int publickey(int g, int x, int p)
{
	unsigned long long int l, pubkey;
	l = pow(g,x);
	pubkey=l % p;
	return pubkey;
}
unsigned long long int secretkey(int G, int x, int p)
{
	unsigned long long int l, seckey;
	l = pow(G,x);
	seckey=l % p;
	return seckey;
}
int main()
{
	int p,g,a,b,t;
	unsigned long long int A, B, secret1, secret2;
	printf("*********Klasik Diffie Hellman Anahtar Degisimi*********\n\n");
	printf("NOT  :  'g' bir tamsayi, 'p' bir asal sayi ve 'p'-1>'g' olmalidir. \n\n");
	
	tekrar2:
	printf("Lutfen ortak 'g' taban degerini giriniz  :  "); 
	scanf("%d", &g);
	tekrar:
	printf("Lutfen ortak 'p' mod degerini giriniz    :  "); 
	scanf("%d", &p);
	
	t=asal(p);
	if(t==1)
	goto tekrar;
	t=aralarindaasal(g,p);
	if(t==1)
	goto tekrar2;
	
	printf("\n\tg  :  %d\n\tp  :  %d\n", g,p);
	
	printf("\nClient gizli degerini giriniz  :  "); 
	scanf("%d", &a);
	printf("Server gizli degerini giriniz  :  ");
	scanf("%d", &b);
	
	printf("\n\ta  :  %llu\n\tb  :  %llu\n", a,b);

	A=publickey(g,a,p);
	B=publickey(g,b,p);
	
	printf("\nPublic Deger Hesaplama=>    A  :  g^a mod p\n");
	printf("                            B  :  g^b mod p\n");
	printf("\nClient public degeri  =>    A  :  %d^%d mod %d\n", g,a,p);
	printf("Server public degeri  =>    B  :  %d^%d mod %d\n\n", g,b,p);
	
	printf("\tA  :  %llu\n\tB  :  %llu\n\n", A,B);

	printf("Gizli Deger Hesaplama => Client  :  B^a mod p  =  g^ba mod p\n");
	printf("                         Server  :  A^b mod p  =  g^ab mod p\n\n");
	printf("Client gizli degeri   =>    s1   :  %llu^%d mod %d\n", B,a,p);
	printf("Server gizli degeri   =>    s2   :  %llu^%d mod %d", A,b,p);
	secret1=secretkey(B,a,p);
	secret2=secretkey(A,b,p);
	
	printf("\n\n\ts1  :  %llu\n\ts2  :  %llu\n", secret1,secret2);
	
	if(secret1!=secret2)
	printf("\n\n's' degerleri esit cikmadi. Islemlerde bir sorun olabilir. \nKontrol ettikten sonra, tekrar deneyiniz.\n\n");
	
	else
	printf("\nOrtak gizli deger     =>    s  :  %llu",secret1);
	
	printf("\n\nClient'in Bildigi Degerler  :  g, p, a, A, B, s\n");
	printf("Server'in Bildigi Degerler  :  g, p, b, B, A, s");
	
	printf("\n\n\n\t*******Tolga Akkapulu*******\n\thttp://www.tolgaakkapulu.com");
	
	getch();
}
