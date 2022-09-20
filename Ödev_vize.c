#include<stdio.h>
#include<locale.h>
#include <string.h> 



typedef struct
{
int hspno;
char ad[10];
char soyad[20];
char tel[11];
int bakiye;	
}kayitlar;

kayitlar musteri[101];  // Kayıtlarda değişiklik yapmak ve sıralama için dizi tanımladım.


void dosya() // kayıt dosyasını oluşturma fonksiyonu 
{
	FILE *dosya;
	dosya=fopen("müşteriler.dat","w");
	char bosalt[]="";
	int i;
	for(i=0;i<=100;i++)
	{
		musteri[i].hspno=-1; // Boş kayıtları -1 yapmak için.
		musteri[i].bakiye=0;
		strcpy(musteri[i].ad,bosalt); // Kayıt dosyasını sıfırlamak istediğimde de kullanmak için boşalttım.
		strcpy(musteri[i].soyad,bosalt);
		strcpy(musteri[i].tel,bosalt);
	}
	for( i=0;i<=100;i++)
	{
		fwrite(&musteri[i],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
	printf("Yeni dosya oluşturuldu\n\n");
}


void diziyeal() //Dosyadaki verileri diziye alma fonksiyonu.
{
	FILE *dosya;
	int j;
	if((dosya=fopen("müşteriler.dat","r"))==NULL)
	{
		printf("Dosya açılamadı!\n");
	}
	for(j=0;j<=100;j++)
	{
		fread(&musteri[j],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
}


void yazdir() // Diziyi dosyaya yazdırma fonksiyonu.
{
	FILE *dosya;
	int j;
	if((dosya=fopen("müşteriler.dat","w"))==NULL)
	{
		printf("Dosya açılamadı!\n");
	}
	for(j=0;j<=100;j++)
	{
		fwrite(&musteri[j],sizeof(musteri),1,dosya);
	}
	fclose(dosya);
}


void kytekleme() //Yeni kayıt ekleme fonksiyonu.
{	
	int i;
	int secim=1;
	while(secim==1)   // Var olan kayıtları diziye alma fonksiyonunu main de çağırdım. Ekleme işlemi için dizide değişiklik yaptık.
	{
		fflush(stdin);
		printf("\nMüşterinin hesap numarasını giriniz. (1-100 arası)\n"); 
		scanf("%d",&i);
		fflush(stdin);
		musteri[i].hspno=i;
		printf("Müşterinin adını giriniz. (max 10 karakter)\n");
		scanf("%s",&musteri[i].ad);
		fflush(stdin);
		printf("Müşterinin soyadını giriniz. (max 20 karakter)\n");
		scanf("%s",&musteri[i].soyad);
		fflush(stdin);
		printf("Müşterinin telefon numarasını giriniz. (başında '0' olmadan)\n");
		scanf("%s",&musteri[i].tel);
		fflush(stdin);
		printf("Müşterinin bakiyesini giriniz. (-50000,+50000 arası)\n");
		scanf("%d",&musteri[i].bakiye);
		fflush(stdin);
		printf("Müşteri kayıtlarına devam etmek için => 1\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
		if(secim==0)
		{
			break; // Ekleme işlemi bitince main de çağırılan dosyaya yazma fonksiyonu çalışacak ve dosyaya kaydedilicek.
		}
	}
}

void kytguncelleme() // Var olan kaydı güncelleme fonksiyonu.
{
	int i,secim;
	while(1)        // Var olan kayıtları diziye alma fonksiyonunu main de çağırdım. Değiştirme işlemi için dizide değişiklik yaptık.
	{
		fflush(stdin);
	printf("\nBakiyesini Değiştirmek için => 1\n");
	printf("Adını değiştirmek için => 2\n");
	printf("Soyadını değiştirmek için => 3\n");
	printf("Telefon numarasını değiştirmek için => 4\n");
	printf("Ana menüye dönmek için => 0\n\n");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
			printf("Güncellemek istediğiniz hesap numarasını giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni bakiyeyi giriniz.(-50000,+50000 arası)\n");
			scanf("%d",&musteri[i].bakiye);
			break;
		case 2:
			printf("Güncellemek istediğiniz hesap numarasını giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni adı giriniz.(max 10 karakter)\n");
			scanf("%s",&musteri[i].ad);
			break;
		case 3:
			printf("Güncellemek istediğiniz hesap numarasını giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni soyadı giriniz.(max 20 karakter)\n");
			scanf("%s",&musteri[i].soyad);
			break;
		case 4:
			printf("Güncellemek istediğiniz hesap numarasını giriniz. (1-100)\n");
			scanf("%d",&i);
			printf("Lütfen yeni telefon numarasını giriniz.(başında '0' olmadan)\n");
			scanf("%s",&musteri[i].tel);		
			break;
		case 0:
			break;
		default:
		printf("\nGeçersiz bir giriş yaptınız!\n\n");
	}
		if(secim==0)
		{
			break; // Bu işlem sonunda da yazdırma fonksiyonu main de çalışacak.
		}
	}
}


void kytgoruntuleme() // Kayıtları görüntüleme fonksiyonu.
{
	FILE *dosya;
	if((dosya=fopen("müşteriler.dat","r"))==NULL)
	{
		printf("Dosya açılamadı!\n");
	}
	int a,secim=1;
	while(secim==1)
	{
		system("cls");
		system("color f");	
		printf("\nGörüntülemek istediğiniz kaydın hesap numarasını giriniz.(1-100)\n");
		scanf("%d",&a);
		fflush(stdin);
		fseek(dosya,sizeof(musteri)*(a),SEEK_SET);   // Dosyada istediğimiz veriye ulaştık.
		if(fread(&musteri[a],sizeof(musteri),1,dosya)==1) // ve okuduk.
		{
			printf("\nHesap Numarası: %d",musteri[a].hspno);
			printf("\nAdı: %s",musteri[a].ad);
			printf("\nSoyadı: %s",musteri[a].soyad);
			printf("\nTelefon Numarası: %s",musteri[a].tel);
			printf("\nBakiye: %d\n\n",musteri[a].bakiye);
		}
		else
		{
			printf("Kayıt bulunamadı.Böyle bir kayıt yok\n\n");
		}
		if(musteri[a].hspno==-1)
		{
			printf("!!Kayıt boş!!\n");
		}
		printf("\nKayıt görüntülemeye devam etmek için => 1\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
	}
	fclose(dosya);
}

void silme() // Kayıt silme fonksiyonu.
{
	int secim,i;
	char bosalt[]="";
	do                   // Yine diziye alma ve dosyaya yazma fonksiyonları main de çağırıldı.
	{
		system("cls");
		system("color c");
		fflush(stdin);
		printf("\nSilmek istediğiniz kaydın hesap numarasını giriniz.(1-100)\n");
		scanf("%d",&i);
		musteri[i].hspno=-1;
		musteri[i].bakiye=0;
		strcpy(musteri[i].ad,bosalt);
		strcpy(musteri[i].soyad,bosalt);
		strcpy(musteri[i].tel,bosalt);
		printf("\nBaşka bir kaydı silmek için => 1\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
	}while(secim==1);
}

void listeleme() // Kayıtları .txt dosyasında listleme fonksiyonu.
{
	kayitlar temp; // Sıralarken tutucu struct olması için tanımladım.
	int i,j,secim;
	FILE *f;
	do
	{
		system("cls");
		system("color d");
		fflush(stdin);
		printf("\nAda göre sıralamak için => 1\n");
		printf("Bakiyeye göre sıralamak için => 2\n");
		printf("Borçluları sıralamak için => 3\n");
		printf("Borçlu olmayanları sıralamak için => 4\n");
		printf("Tüm kayıtları hesap numarasına göre sıralamak için => 5\n");
		printf("Ana menüye dönmek için => 0\n\n");
		scanf("%d",&secim);
		fflush(stdin);
		switch(secim)
		{
			case 1:
				for (i = 1; i <=100; i++)         // Sıralama algoritması.
    			{
					for (j = 0; j <=100-i; j++)
					{
						if (strcmp(musteri[j].ad,musteri[j+1].ad) > 0) // isme göre sıralamak için strcmp kullandım.
           				{
              				temp=musteri[j];
               				musteri[j]=musteri[j+1];
               				musteri[j+1]=temp;
           				 }
        			}
   				}
   				
   				if((f=fopen("Ada göre_sıralı liste.txt","w"))==NULL)
				{
					printf("Dosya oluşturulamadı!\n");
				}
				for(i=0;i<=100;i++)
				{
					if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
					{
						fprintf(f,"Adı: %s\n",musteri[i].ad);
						fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
						fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
						fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
						fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
					}
				}
				printf("\nDosyanız Hazır!\n");
				fclose(f);
				printf("\nListe oluşturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
			
			case 2:
				fflush(stdin);
				printf("Küçükten büyüğe göre sıralamak için => 1\n");
				printf("Büyükten küçüğe sıralamak için => 2\n");
				scanf("%d",&secim);
				fflush(stdin);
				for (i = 1; i <=100; i++)
                    {
                    	for (j = 0; j <=100-i; j++)
                        {
							if (musteri[j].bakiye>musteri[j+1].bakiye) // Bakiyeye göre sıralanma.
                            {
                            	temp=musteri[j];
                            	musteri[j]=musteri[j+1];
                            	musteri[j+1]=temp;
                            }
                        }
                    }
				if(secim==1)
				{
   					if((f=fopen("Bakiyeye göre sıralı liste (Küçükten büyüğe).txt","w"))==NULL)
					{
						printf("Dosya oluşturulamadı!\n");
					}
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
						{
							fprintf(f,"Adı: %s\n",musteri[i].ad);
							fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
					fclose(f);
				}
				
				
				if(secim==2)
				{
					fflush(stdin);
   					if((f=fopen("Bakiyeye göre_sıralı liste (Büyükten küçüğe).txt","w"))==NULL)
					{
						printf("Dosya oluşturulamadı!\n");
					}
					for(i=100;i>=0;i--) // zaten küçükten büyüğe sıralamıştım tersten yazdırdım direkt.
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
						{
							fprintf(f,"Adı: %s\n",musteri[i].ad);
							fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
					fclose(f);
				}
				printf("\nDosyanız Hazır!\n");
				printf("\nListe oluşturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
				
			case 3:
				fflush(stdin);
   				printf("\nKüçükten büyüğe sıralamak için => 1\n");
   				printf("Büyükten küçüğe sıralamak için => 2\n");
   				scanf("%d",&secim);
   				fflush(stdin);
   				if((f=fopen("Borçlu listesi.txt","w"))==NULL)
				{
					printf("Dosya oluşturulamadı!\n");
				}
				if(secim==1)
				{
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if((musteri[i].hspno!=-1) && (musteri[i].bakiye<0) && musteri[i].hspno!=0) // sadece borçlular yazdırılsın diye.
						{
							fprintf(f,"Adı: %s\n",musteri[i].ad);
							fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
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
							fprintf(f,"Adı: %s\n",musteri[i].ad);
							fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				printf("\nDosyanız Hazır!\n");
				fclose(f);
				printf("\nListe oluşturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
				
			case 4:
				fflush(stdin);
   				printf("\nKüçükten büyüğe sıralamak için => 1\n");
   				printf("Büyükten küçüğe sıralamak için => 2\n");
   				scanf("%d",&secim);
   				fflush(stdin);
   				if((f=fopen("Borçlu olmayanların listesi.txt","w"))==NULL)
				{
					printf("Dosya oluşturulamadı!\n");
				}
				if(secim==1)
				{
					for(i=0;i<=100;i++)
					{
						fflush(stdin);
						if(musteri[i].hspno!=-1 && musteri[i].bakiye>0 && musteri[i].hspno!=0) // borçlu olmayanlar yazdırılsın diye.
						{
							fprintf(f,"Adı: %s\n",musteri[i].ad);
							fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
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
							fprintf(f,"Adı: %s\n",musteri[i].ad);
							fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
							fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
							fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
							fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
						}
					}
				}
				printf("\nDosyanız Hazır!\n");
				fclose(f);
				printf("\nListe oluşturmaya devam etmek için => 1\n");
				printf("Ana menüye dönmek için => 0\n\n");
				scanf("%d",&secim);
				fflush(stdin);
				break;
			
			case 5:
				diziyeal(); // Başka bir listeleme işleminden sonra yapılırsa hesap numarasına göre sıralı olmadığı için tekrar diziye alma fonksiyonu çağırdım.
				fflush(stdin);
   				if((f=fopen("Tüm kayıtların listesi.txt","w"))==NULL)
				{
					printf("Dosya oluşturulamadı!\n");
				}
				for(i=0;i<=100;i++)
				{
					fflush(stdin);
					if(musteri[i].hspno!=-1 && musteri[i].hspno!=0)
					{
						fprintf(f,"Adı: %s\n",musteri[i].ad);
						fprintf(f,"Soyadı: %s\n",musteri[i].soyad);
						fprintf(f,"Hesap numarası: %d\n",musteri[i].hspno);
						fprintf(f,"Telefon numarası: %s\n",musteri[i].tel);
						fprintf(f,"Bakiyesi: %d\n\n",musteri[i].bakiye);
					}
				}
				printf("\nDosyanız Hazır!\n");
				fclose(f);
				printf("\nListe oluşturmaya devam etmek için => 1\n");
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
	system("COLOR e"); // Göz yormaması ve anlaşılırlığı arttırmak için temizleme ve renk değiştirme kullandım.
	system("cls");
	fflush(stdin);
		printf("*****ANA MENÜ*****\n\n");
		printf("Kayıt Dosyanız Yoksa 1. Seçeneği Seçiniz!!!!\n");
		printf("Kayıt dosyasını sıfırlamak için yada dosya yoksa oluşturmak için => 1 (NOT:Eski kayıt silinir)\n");
		printf("Yeni kayıt eklemek için => 2\n");
		printf("Kayıt güncelleme için => 3\n");
		printf("Kayıt görüntüleme için => 4\n");
		printf("Kayıt silme için => 5\n");
		printf("Kayıtları listelemek için => 6\n");
		printf("Çıkmak için => 0\n");
		scanf("%d",&secim);
		fflush(stdin); // Bellekte tampon görevi gören bir fonksiyonmuş. Bazı problemlerin önüne geçti. (scanf vs.)
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
			diziyeal(); // Diziye alma ve yazdırma fonksiyonlarını main de çağırdım.
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
