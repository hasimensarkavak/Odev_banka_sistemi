#include<stdio.h>
#include<locale.h>
#include <string.h> 

//Haþim Ensar Kavak 2018280027

typedef struct
{
int hspno;
char ad[10];
char soyad[20];
char tel[11];
int bakiye;	
}kayitlar;

kayitlar musteri[101];  // Kayýtlarda deðiþiklik yapmak ve sýralama için dizi tanýmladým.


void dosya() // kayýt dosyasýný oluþturma fonksiyonu 
{
	FILE *dosya;
	dosya=fopen("müþteriler.dat","w");
	char bosalt[]="";
	int i;
	for(i=0;i<=100;i++)
	{
		musteri[i].hspno=-1; // Boþ kayýtlarý -1 yapmak için.
		musteri[i].bakiye=0;
		strcpy(musteri[i].ad,bosalt); // Kayýt dosyasýný sýfýrlamak istediðimde de kullanmak için boþalttým.
		strcpy(musteri[i].soyad,bosalt);
		strcpy(musteri[i].tel,bosalt);
	}
	for( i=0;i<=100;i++)
	{
		fwrite(&musteri[i],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
	printf("Yeni dosya oluþturuldu\n\n");
}


void diziyeal() //Dosyadaki verileri diziye alma fonksiyonu.
{
	FILE *dosya;
	int j;
	if((dosya=fopen("müþteriler.dat","r"))==NULL)
	{
		printf("Dosya açýlamadý!\n");
	}
	for(j=0;j<=100;j++)
	{
		fread(&musteri[j],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
}


void yazdir() // Diziyi dosyaya yazdýrma fonksiyonu.
{
	FILE *dosya;
	int j;
	if((dosya=fopen("müþteriler.dat","w"))==NULL)
	{
		printf("Dosya açýlamadý!\n");
	}
	for(j=0;j<=100;j++)
	{
		fwrite(&musteri[j],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
}


void kytekleme() //Yeni kayýt ekleme fonksiyonu.
{	
	int i;
	int secim=1;
	while(secim==1)   // Var olan kayýtlarý diziye alma fonksiyonunu main de çaðýrdým. Ekleme iþlemi için dizide deðiþiklik yaptýk.
	{
		fflush(stdin);
		printf("\nMüþterinin hesap numarasýný giriniz. (1-100 arasý)\n"); 
		scanf("%d",&i);
		fflush(stdin);
		musteri[i].hspno=i;
		printf("Müþterinin adýný giriniz. (max 10 karakter)\n");
		scanf("%s",&musteri[i].ad);
		fflush(stdin);
		printf("Müþterinin soyadýný giriniz. (max 20 karakter)\n");
		scanf("%s",&musteri[i].soyad);
		fflush(stdin);
		printf("Müþterinin telefon numarasýný giriniz. (baþýnda '0' olmadan)\n");
		scanf("%s",&musteri[i].tel);
		fflush(stdin);
		printf("Müþterinin bakiyesini giriniz. (-50000,+50000 arasý)\n");
		scanf("%d",&musteri[i].bakiye);
		fflush(stdin);
		printf("Müþteri kayýtlarýna devam etmek için => 1\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
		if(secim==0)
		{
			break; // Ekleme iþlemi bitince main de çaðýrýlan dosyaya yazma fonksiyonu çalýþacak ve dosyaya kaydedilicek.
		}
	}
}

void kytguncelleme() // Var olan kaydý güncelleme fonksiyonu.
{
	int i,secim;
	while(1)        // Var olan kayýtlarý diziye alma fonksiyonunu main de çaðýrdým. Deðiþtirme iþlemi için dizide deðiþiklik yaptýk.
	{
		fflush(stdin);
	printf("\nBakiyesini Deðiþtirmek için => 1\n");
	printf("Adýný deðiþtirmek için => 2\n");
	printf("Soyadýný deðiþtirmek için => 3\n");
	printf("Telefon numarasýný deðiþtirmek için => 4\n");
	printf("Ana menüye dönmek için => 0\n\n");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
			printf("Güncellemek istediðiniz hesap numarasýný giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni bakiyeyi giriniz.(-50000,+50000 arasý)\n");
			scanf("%d",&musteri[i].bakiye);
			break;
		case 2:
			printf("Güncellemek istediðiniz hesap numarasýný giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni adý giriniz.(max 10 karakter)\n");
			scanf("%s",&musteri[i].ad);
			break;
		case 3:
			printf("Güncellemek istediðiniz hesap numarasýný giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni soyadý giriniz.(max 20 karakter)\n");
			scanf("%s",&musteri[i].soyad);
			break;
		case 4:
			printf("Güncellemek istediðiniz hesap numarasýný giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni telefon numarasýný giriniz.(baþýnda '0' olmadan)\n");
			scanf("%s",&musteri[i].tel);		
			break;
		case 0:
			break;
		default:
		printf("\nGeçersiz bir giriþ yaptýnýz!\n\n");
	}
		if(secim==0)
		{
			break; // Bu iþlem sonunda da yazdýrma fonksiyonu main de çalýþacak.
		}
	}
}


void kytgoruntuleme() // Kayýtlarý görüntüleme fonksiyonu.
{
	FILE *dosya;
	if((dosya=fopen("müþteriler.dat","r"))==NULL)
	{
		printf("Dosya açýlamadý!\n");
	}
	int a,secim=1;
	while(secim==1)
	{
		system("cls");
		system("color f");	
		printf("\nGörüntülemek istediðiniz kaydýn hesap numarasýný giriniz.(1-100)\n");
		scanf("%d",&a);
		fflush(stdin);
		fseek(dosya,sizeof(musteri)*(a),SEEK_SET);   // Dosyada istediðimiz veriye ulaþtýk.
		if(fread(&musteri[a],sizeof(musteri),1,dosya)==1) // ve okuduk.
		{
			printf("\nHesap Numarasý: %d",musteri[a].hspno);
			printf("\nAdý: %s",musteri[a].ad);
			printf("\nSoyadý: %s",musteri[a].soyad);
			printf("\nTelefon Numarasý: %s",musteri[a].tel);
			printf("\nBakiye: %d\n\n",musteri[a].bakiye);
		}
		else
		{
			printf("Kayýt bulunamadý.Böyle bir kayýt yok\n\n");
		}
		if(musteri[a].hspno==-1)
		{
			printf("!!Kayýt boþ!!\n");
		}
		printf("\nKayýt görüntülemeye devam etmek için => 1\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
	}
	fclose(dosya);
}

void silme() // Kayýt silme fonksiyonu.
{
	int secim,i;
	char bosalt[]="";
	do                   // Yine diziye alma ve dosyaya yazma fonksiyonlarý main de çaðýrýldý.
	{
		system("cls");
		system("color c");
		fflush(stdin);
		printf("\nSilmek istediðiniz kaydýn hesap numarasýný giriniz.(1-100)\n");
		scanf("%d",&i);
		musteri[i].hspno=-1;
		musteri[i].bakiye=0;
		strcpy(musteri[i].ad,bosalt);
		strcpy(musteri[i].soyad,bosalt);
		strcpy(musteri[i].tel,bosalt);
		printf("\nBaþka bir kaydý silmek için => 1\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
	}while(secim==1);
}

void listeleme() // Kayýtlarý .txt dosyasýnda listleme fonksiyonu.
{
	kayitlar temp; // Sýralarken tutucu struct olmasý için tanýmladým.
	int i,j,secim;
	FILE *f;
	do
	{
		system("cls");
		system("color d");
		fflush(stdin);
		printf("\nAda göre sýralamak için => 1\n");
		printf("Bakiyeye göre sýralamak için => 2\n");
		printf("Borçlularý sýralamak için => 3\n");
		printf("Borçlu olmayanlarý sýralamak için => 4\n");
		printf("Tüm kayýtlarý hesap numarasýna göre sýralamak için => 5\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
		switch(secim)
		{
			case 1:
				for (i = 1; i <=100; i++)         // Sýralama algoritmasý.
    			{
					for (j = 0; j <=100-i; j++)
					{
						if (strcmp(musteri[j].ad,musteri[j+1].ad) > 0) // isme göre sýralamak için strcmp kullandým.
           				{
              				temp=musteri[j];
               				musteri[j]=musteri[j+1];
               				musteri[j+1]=temp;
           				 }
        			}
   				}
   				
   				if((f=fopen("Ada göre_sýralý liste.txt","w"))==NULL)
				{
					printf("Dosya oluþturulamadý!\n");
				}
				for(i=0;i<=100;i++)
				{
					if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
					{
						fprintf(f,"Adý: %s\n",musteri[i].ad);
						fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
						fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
						fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
						fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
					}
				}
				printf("\nDosyanýz Hazýr!\n");
				fclose(f);
				printf("\nListe oluþturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
			
			case 2:
				fflush(stdin);
				printf("Küçükten büyüðe göre sýralamak için => 1\n");
				printf("Büyükten küçüðe sýralamak için => 2\n");
				scanf("%d",&secim);
				fflush(stdin);
				for (i = 1; i <=100; i++)
                    {
                    	for (j = 0; j <=100-i; j++)
                        {
							if (musteri[j].bakiye>musteri[j+1].bakiye) // Bakiyeye göre sýralanma.
                            {
                            	temp=musteri[j];
                            	musteri[j]=musteri[j+1];
                            	musteri[j+1]=temp;
                            }
                        }
                    }
				if(secim==1)
				{
   					if((f=fopen("Bakiyeye göre sýralý liste (Küçükten büyüðe).txt","w"))==NULL)
					{
						printf("Dosya oluþturulamadý!\n");
					}
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
						{
							fprintf(f,"Adý: %s\n",musteri[i].ad);
							fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
					fclose(f);
				}
				
				
				if(secim==2)
				{
					fflush(stdin);
   					if((f=fopen("Bakiyeye göre_sýralý liste (Büyükten küçüðe).txt","w"))==NULL)
					{
						printf("Dosya oluþturulamadý!\n");
					}
					for(i=100;i>=0;i--) // zaten küçükten büyüðe sýralamýþtým tersten yazdýrdým direkt.
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
						{
							fprintf(f,"Adý: %s\n",musteri[i].ad);
							fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
					fclose(f);
				}
				printf("\nDosyanýz Hazýr!\n");
				printf("\nListe oluþturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
				
			case 3:
				fflush(stdin);
   				printf("\nKüçükten büyüðe sýralamak için => 1\n");
   				printf("Büyükten küçüðe sýralamak için => 2\n");
   				scanf("%d",&secim);
   				fflush(stdin);
   				if((f=fopen("Borçlu listesi.txt","w"))==NULL)
				{
					printf("Dosya oluþturulamadý!\n");
				}
				if(secim==1)
				{
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if((musteri[i].hspno!=-1) && (musteri[i].bakiye<0) && musteri[i].hspno!=0) // sadece borçlular yazdýrýlsýn diye.
						{
							fprintf(f,"Adý: %s\n",musteri[i].ad);
							fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
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
							fprintf(f,"Adý: %s\n",musteri[i].ad);
							fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				printf("\nDosyanýz Hazýr!\n");
				fclose(f);
				printf("\nListe oluþturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
				
			case 4:
				fflush(stdin);
   				printf("\nKüçükten büyüðe sýralamak için => 1\n");
   				printf("Büyükten küçüðe sýralamak için => 2\n");
   				scanf("%d",&secim);
   				fflush(stdin);
   				if((f=fopen("Borçlu olmayanlarýn listesi.txt","w"))==NULL)
				{
					printf("Dosya oluþturulamadý!\n");
				}
				if(secim==1)
				{
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].bakiye>0 && musteri[i].hspno!=0) // borçlu olmayanlar yazdýrýlsýn diye.
						{
							fprintf(f,"Adý: %s\n",musteri[i].ad);
							fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
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
							fprintf(f,"Adý: %s\n",musteri[i].ad);
							fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				printf("\nDosyanýz Hazýr!\n");
				fclose(f);
				printf("\nListe oluþturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
			
			case 5:
				diziyeal(); // Baþka bir listeleme iþleminden sonra yapýlýrsa hesap numarasýna göre sýralý olmadýðý için tekrar diziye alma fonksiyonu çaðýrdým.
				fflush(stdin);
   				if((f=fopen("Tüm kayýtlarýn listesi.txt","w"))==NULL)
				{
					printf("Dosya oluþturulamadý!\n");
				}
				for(i=0;i<=100;i++)
				{
					fflush(stdin);
					if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
					{
						fprintf(f,"Adý: %s\n",musteri[i].ad);
						fprintf(f,"Soyadý: %s\n",musteri[i].soyad);
						fprintf(f,"Hesap numarasý: %d\n",musteri[i].hspno);
						fprintf(f,"Telefon numarasý: %s\n",musteri[i].tel);
						fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
					}
				}
				printf("\nDosyanýz Hazýr!\n");
				fclose(f);
				printf("\nListe oluþturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
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
	system("COLOR e"); // Göz yormamasý ve anlaþýlýrlýðý arttýrmak için temizleme ve renk deðiþtirme kullandým.
	system("cls");
	fflush(stdin);
		printf("*****ANA MENÜ*****\n\n");
		printf("Kayýt Dosyanýz Yoksa 1. Seçeneði Seçiniz!!!!\n");
		printf("Kayýt dosyasýný sýfýrlamak için yada dosya yoksa oluþturmak için => 1 (NOT:Eski kayýt silinir)\n");
		printf("Yeni kayýt eklemek için => 2\n");
		printf("Kayýt güncelleme için => 3\n");
		printf("Kayýt görüntüleme için => 4\n");
		printf("Kayýt silme için => 5\n");
		printf("Kayýtlarý listelemek için => 6\n");
		printf("Çýkmak için => 0\n");
		scanf("%d",&secim);
		fflush(stdin); // Bellekte tampon görevi gören bir fonksiyonmuþ. Bazý problemlerin önüne geçti. (scanf vs.)
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
			diziyeal(); // Diziye alma ve yazdýrma fonksiyonlarýný main de çaðýrdým.
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
