#include<stdio.h>
#include<locale.h>
#include <string.h> 

//Ha�im Ensar Kavak 2018280027

typedef struct
{
int hspno;
char ad[10];
char soyad[20];
char tel[11];
int bakiye;	
}kayitlar;

kayitlar musteri[101];  // Kay�tlarda de�i�iklik yapmak ve s�ralama i�in dizi tan�mlad�m.


void dosya() // kay�t dosyas�n� olu�turma fonksiyonu 
{
	FILE *dosya;
	dosya=fopen("m��teriler.dat","w");
	char bosalt[]="";
	int i;
	for(i=0;i<=100;i++)
	{
		musteri[i].hspno=-1; // Bo� kay�tlar� -1 yapmak i�in.
		musteri[i].bakiye=0;
		strcpy(musteri[i].ad,bosalt); // Kay�t dosyas�n� s�f�rlamak istedi�imde de kullanmak i�in bo�altt�m.
		strcpy(musteri[i].soyad,bosalt);
		strcpy(musteri[i].tel,bosalt);
	}
	for( i=0;i<=100;i++)
	{
		fwrite(&musteri[i],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
	printf("Yeni dosya olu�turuldu\n\n");
}


void diziyeal() //Dosyadaki verileri diziye alma fonksiyonu.
{
	FILE *dosya;
	int j;
	if((dosya=fopen("m��teriler.dat","r"))==NULL)
	{
		printf("Dosya a��lamad�!\n");
	}
	for(j=0;j<=100;j++)
	{
		fread(&musteri[j],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
}


void yazdir() // Diziyi dosyaya yazd�rma fonksiyonu.
{
	FILE *dosya;
	int j;
	if((dosya=fopen("m��teriler.dat","w"))==NULL)
	{
		printf("Dosya a��lamad�!\n");
	}
	for(j=0;j<=100;j++)
	{
		fwrite(&musteri[j],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
}


void kytekleme() //Yeni kay�t ekleme fonksiyonu.
{	
	int i;
	int secim=1;
	while(secim==1)   // Var olan kay�tlar� diziye alma fonksiyonunu main de �a��rd�m. Ekleme i�lemi i�in dizide de�i�iklik yapt�k.
	{
		fflush(stdin);
		printf("\nM��terinin hesap numaras�n� giriniz. (1-100 aras�)\n"); 
		scanf("%d",&i);
		fflush(stdin);
		musteri[i].hspno=i;
		printf("M��terinin ad�n� giriniz. (max 10 karakter)\n");
		scanf("%s",&musteri[i].ad);
		fflush(stdin);
		printf("M��terinin soyad�n� giriniz. (max 20 karakter)\n");
		scanf("%s",&musteri[i].soyad);
		fflush(stdin);
		printf("M��terinin telefon numaras�n� giriniz. (ba��nda '0' olmadan)\n");
		scanf("%s",&musteri[i].tel);
		fflush(stdin);
		printf("M��terinin bakiyesini giriniz. (-50000,+50000 aras�)\n");
		scanf("%d",&musteri[i].bakiye);
		fflush(stdin);
		printf("M��teri kay�tlar�na devam etmek i�in => 1\n");
		printf("Ana men�ye d�nmek i�in => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
		if(secim==0)
		{
			break; // Ekleme i�lemi bitince main de �a��r�lan dosyaya yazma fonksiyonu �al��acak ve dosyaya kaydedilicek.
		}
	}
}

void kytguncelleme() // Var olan kayd� g�ncelleme fonksiyonu.
{
	int i,secim;
	while(1)        // Var olan kay�tlar� diziye alma fonksiyonunu main de �a��rd�m. De�i�tirme i�lemi i�in dizide de�i�iklik yapt�k.
	{
		fflush(stdin);
	printf("\nBakiyesini De�i�tirmek i�in => 1\n");
	printf("Ad�n� de�i�tirmek i�in => 2\n");
	printf("Soyad�n� de�i�tirmek i�in => 3\n");
	printf("Telefon numaras�n� de�i�tirmek i�in => 4\n");
	printf("Ana men�ye d�nmek i�in => 0\n\n");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
			printf("G�ncellemek istedi�iniz hesap numaras�n� giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("L�tfen yeni bakiyeyi giriniz.(-50000,+50000 aras�)\n");
			scanf("%d",&musteri[i].bakiye);
			break;
		case 2:
			printf("G�ncellemek istedi�iniz hesap numaras�n� giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("L�tfen yeni ad� giriniz.(max 10 karakter)\n");
			scanf("%s",&musteri[i].ad);
			break;
		case 3:
			printf("G�ncellemek istedi�iniz hesap numaras�n� giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("L�tfen yeni soyad� giriniz.(max 20 karakter)\n");
			scanf("%s",&musteri[i].soyad);
			break;
		case 4:
			printf("G�ncellemek istedi�iniz hesap numaras�n� giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("L�tfen yeni telefon numaras�n� giriniz.(ba��nda '0' olmadan)\n");
			scanf("%s",&musteri[i].tel);		
			break;
		case 0:
			break;
		default:
		printf("\nGe�ersiz bir giri� yapt�n�z!\n\n");
	}
		if(secim==0)
		{
			break; // Bu i�lem sonunda da yazd�rma fonksiyonu main de �al��acak.
		}
	}
}


void kytgoruntuleme() // Kay�tlar� g�r�nt�leme fonksiyonu.
{
	FILE *dosya;
	if((dosya=fopen("m��teriler.dat","r"))==NULL)
	{
		printf("Dosya a��lamad�!\n");
	}
	int a,secim=1;
	while(secim==1)
	{
		system("cls");
		system("color f");	
		printf("\nG�r�nt�lemek istedi�iniz kayd�n hesap numaras�n� giriniz.(1-100)\n");
		scanf("%d",&a);
		fflush(stdin);
		fseek(dosya,sizeof(musteri)*(a),SEEK_SET);   // Dosyada istedi�imiz veriye ula�t�k.
		if(fread(&musteri[a],sizeof(musteri),1,dosya)==1) // ve okuduk.
		{
			printf("\nHesap Numaras�: %d",musteri[a].hspno);
			printf("\nAd�: %s",musteri[a].ad);
			printf("\nSoyad�: %s",musteri[a].soyad);
			printf("\nTelefon Numaras�: %s",musteri[a].tel);
			printf("\nBakiye: %d\n\n",musteri[a].bakiye);
		}
		else
		{
			printf("Kay�t bulunamad�.B�yle bir kay�t yok\n\n");
		}
		if(musteri[a].hspno==-1)
		{
			printf("!!Kay�t bo�!!\n");
		}
		printf("\nKay�t g�r�nt�lemeye devam etmek i�in => 1\n");
		printf("Ana men�ye d�nmek i�in => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
	}
	fclose(dosya);
}

void silme() // Kay�t silme fonksiyonu.
{
	int secim,i;
	char bosalt[]="";
	do                   // Yine diziye alma ve dosyaya yazma fonksiyonlar� main de �a��r�ld�.
	{
		system("cls");
		system("color c");
		fflush(stdin);
		printf("\nSilmek istedi�iniz kayd�n hesap numaras�n� giriniz.(1-100)\n");
		scanf("%d",&i);
		musteri[i].hspno=-1;
		musteri[i].bakiye=0;
		strcpy(musteri[i].ad,bosalt);
		strcpy(musteri[i].soyad,bosalt);
		strcpy(musteri[i].tel,bosalt);
		printf("\nBa�ka bir kayd� silmek i�in => 1\n");
		printf("Ana men�ye d�nmek i�in => 0\n\n");
		scanf("%d",&secim);
	}while(secim==1);
}

void listeleme() // Kay�tlar� .txt dosyas�nda listleme fonksiyonu.
{
	kayitlar temp; // S�ralarken tutucu struct olmas� i�in tan�mlad�m.
	int i,j,secim;
	FILE *f;
	do
	{
		system("cls");
		system("color d");
		fflush(stdin);
		printf("\nAda g�re s�ralamak i�in => 1\n");
		printf("Bakiyeye g�re s�ralamak i�in => 2\n");
		printf("Bor�lular� s�ralamak i�in => 3\n");
		printf("Bor�lu olmayanlar� s�ralamak i�in => 4\n");
		printf("T�m kay�tlar� hesap numaras�na g�re s�ralamak i�in => 5\n");
		printf("Ana men�ye d�nmek i�in => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
		switch(secim)
		{
			case 1:
				for (i = 1; i <=100; i++)         // S�ralama algoritmas�.
    			{
					for (j = 0; j <=100-i; j++)
					{
						if (strcmp(musteri[j].ad,musteri[j+1].ad) > 0) // isme g�re s�ralamak i�in strcmp kulland�m.
           				{
              				temp=musteri[j];
               				musteri[j]=musteri[j+1];
               				musteri[j+1]=temp;
           				 }
        			}
   				}
   				
   				if((f=fopen("Ada g�re_s�ral� liste.txt","w"))==NULL)
				{
					printf("Dosya olu�turulamad�!\n");
				}
				for(i=0;i<=100;i++)
				{
					if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
					{
						fprintf(f,"Ad�: %s\n",musteri[i].ad);
						fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
						fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
						fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
						fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
					}
				}
				printf("\nDosyan�z Haz�r!\n");
				fclose(f);
				printf("\nListe olu�turmaya devam etmek i�in => 1\n");
				printf("Ana men�ye d�nmek i�in => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
			
			case 2:
				fflush(stdin);
				printf("K���kten b�y��e g�re s�ralamak i�in => 1\n");
				printf("B�y�kten k����e s�ralamak i�in => 2\n");
				scanf("%d",&secim);
				fflush(stdin);
				for (i = 1; i <=100; i++)
                    {
                    	for (j = 0; j <=100-i; j++)
                        {
							if (musteri[j].bakiye>musteri[j+1].bakiye) // Bakiyeye g�re s�ralanma.
                            {
                            	temp=musteri[j];
                            	musteri[j]=musteri[j+1];
                            	musteri[j+1]=temp;
                            }
                        }
                    }
				if(secim==1)
				{
   					if((f=fopen("Bakiyeye g�re s�ral� liste (K���kten b�y��e).txt","w"))==NULL)
					{
						printf("Dosya olu�turulamad�!\n");
					}
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
						{
							fprintf(f,"Ad�: %s\n",musteri[i].ad);
							fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
					fclose(f);
				}
				
				
				if(secim==2)
				{
					fflush(stdin);
   					if((f=fopen("Bakiyeye g�re_s�ral� liste (B�y�kten k����e).txt","w"))==NULL)
					{
						printf("Dosya olu�turulamad�!\n");
					}
					for(i=100;i>=0;i--) // zaten k���kten b�y��e s�ralam��t�m tersten yazd�rd�m direkt.
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
						{
							fprintf(f,"Ad�: %s\n",musteri[i].ad);
							fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
					fclose(f);
				}
				printf("\nDosyan�z Haz�r!\n");
				printf("\nListe olu�turmaya devam etmek i�in => 1\n");
				printf("Ana men�ye d�nmek i�in => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
				
			case 3:
				fflush(stdin);
   				printf("\nK���kten b�y��e s�ralamak i�in => 1\n");
   				printf("B�y�kten k����e s�ralamak i�in => 2\n");
   				scanf("%d",&secim);
   				fflush(stdin);
   				if((f=fopen("Bor�lu listesi.txt","w"))==NULL)
				{
					printf("Dosya olu�turulamad�!\n");
				}
				if(secim==1)
				{
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if((musteri[i].hspno!=-1) && (musteri[i].bakiye<0) && musteri[i].hspno!=0) // sadece bor�lular yazd�r�ls�n diye.
						{
							fprintf(f,"Ad�: %s\n",musteri[i].ad);
							fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				if(secim==2)
				{
					for(i=100;i>=0;i--)
					{
						fflush(stdin);
						if((musteri[i].hspno!=-1) && (musteri[i].bakiye<0) && musteri[i].hspno!=0)
						{
							fprintf(f,"Ad�: %s\n",musteri[i].ad);
							fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				printf("\nDosyan�z Haz�r!\n");
				fclose(f);
				printf("\nListe olu�turmaya devam etmek i�in => 1\n");
				printf("Ana men�ye d�nmek i�in => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
				
			case 4:
				fflush(stdin);
   				printf("\nK���kten b�y��e s�ralamak i�in => 1\n");
   				printf("B�y�kten k����e s�ralamak i�in => 2\n");
   				scanf("%d",&secim);
   				fflush(stdin);
   				if((f=fopen("Bor�lu olmayanlar�n listesi.txt","w"))==NULL)
				{
					printf("Dosya olu�turulamad�!\n");
				}
				if(secim==1)
				{
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].bakiye>0 && musteri[i].hspno!=0) // bor�lu olmayanlar yazd�r�ls�n diye.
						{
							fprintf(f,"Ad�: %s\n",musteri[i].ad);
							fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				if(secim==2)
				{
					for(i=100;i>=0;i--)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].bakiye>0 && musteri[i].hspno!=0)
						{
							fprintf(f,"Ad�: %s\n",musteri[i].ad);
							fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				printf("\nDosyan�z Haz�r!\n");
				fclose(f);
				printf("\nListe olu�turmaya devam etmek i�in => 1\n");
				printf("Ana men�ye d�nmek i�in => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
			
			case 5:
				diziyeal(); // Ba�ka bir listeleme i�leminden sonra yap�l�rsa hesap numaras�na g�re s�ral� olmad��� i�in tekrar diziye alma fonksiyonu �a��rd�m.
				fflush(stdin);
   				if((f=fopen("T�m kay�tlar�n listesi.txt","w"))==NULL)
				{
					printf("Dosya olu�turulamad�!\n");
				}
				for(i=0;i<=100;i++)
				{
					fflush(stdin);
					if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
					{
						fprintf(f,"Ad�: %s\n",musteri[i].ad);
						fprintf(f,"Soyad�: %s\n",musteri[i].soyad);
						fprintf(f,"Hesap numaras�: %d\n",musteri[i].hspno);
						fprintf(f,"Telefon numaras�: %s\n",musteri[i].tel);
						fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
					}
				}
				printf("\nDosyan�z Haz�r!\n");
				fclose(f);
				printf("\nListe olu�turmaya devam etmek i�in => 1\n");
				printf("Ana men�ye d�nmek i�in => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
		}
	}while(secim==1);
}


int main()
{
setlocale(LC_ALL, "Turkish"); 

int secim;
	while(1)
	{	
	system("COLOR e"); // G�z yormamas� ve anla��l�rl��� artt�rmak i�in temizleme ve renk de�i�tirme kulland�m.
	system("cls");
	fflush(stdin);
		printf("*****ANA MEN�*****\n\n");
		printf("Kay�t Dosyan�z Yoksa 1. Se�ene�i Se�iniz!!!!\n");
		printf("Kay�t dosyas�n� s�f�rlamak i�in yada dosya yoksa olu�turmak i�in => 1 (NOT:Eski kay�t silinir)\n");
		printf("Yeni kay�t eklemek i�in => 2\n");
		printf("Kay�t g�ncelleme i�in => 3\n");
		printf("Kay�t g�r�nt�leme i�in => 4\n");
		printf("Kay�t silme i�in => 5\n");
		printf("Kay�tlar� listelemek i�in => 6\n");
		printf("��kmak i�in => 0\n");
		scanf("%d",&secim);
		fflush(stdin); // Bellekte tampon g�revi g�ren bir fonksiyonmu�. Baz� problemlerin �n�ne ge�ti. (scanf vs.)
		if(secim==0)
		{
			break;
		}
		
		if(secim==1)
		{
			dosya();
		}
		
		if(secim==2)
		{
			system("cls");
			system("color a");
			diziyeal(); // Diziye alma ve yazd�rma fonksiyonlar�n� main de �a��rd�m.
			kytekleme();
			yazdir();
		}
		if(secim==3)
		{
			system("cls");
			system("color b");
			diziyeal();
			kytguncelleme();
			yazdir();
		}
		if(secim==4)
		{
			kytgoruntuleme();
		}
		if(secim==5)
		{
			diziyeal();
			silme();
			yazdir();
		}
		if(secim==6)
		{
			diziyeal();
			listeleme();
		}
	}

}

/* Kaynaklar

http://www.ibrahimbayraktar.net/2017/08/c-programlama-ornek-kelimeleri.html
https://www.bilgigunlugum.net/prog/cprog/c_stdkut/string/strcmp
https://www.daniweb.com/programming/software-development/threads/100744/system
http://sharpsharp.blogcu.com/c-dili-ve-scanf-sorunu/1967218
*/ 
