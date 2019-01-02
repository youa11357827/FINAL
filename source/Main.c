/* Fig 10.3: fig10_03.c
   The card shuffling and dealing program using structures */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

   /* card structure definition */
struct card {
	const char *face; /* define pointer face */
	const char *suit; /* define pointer face */
};/* end structure card*/

typedef struct card Card;/* new type name for struct card*/
void compare(Card  *wDeck);
/* prototypes */
void fillDeck(Card * const wDeck, const char * wFace[],
	const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void)
{
	Card deck[52];/*define array of Cards*/
	int heart = 0;
	/* initialize array of pointers */
	const int face[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	const char *suit[] = { "紅心","方塊","梅花","黑桃" };

	srand(time(NULL));/* randomize */

	fillDeck(deck, face, suit);/* load the deck with Cards */
	shuffle(deck);
	compare(deck);
	/* put Card in random order */
	deal(deck);/* deal all 52 Cards*/
	system("pause");
	return 0;/* indicates successful termination */
}/* end main */

void compare(Card  *wDeck)
{
	int formpl = 0, numpl[20] = { 0 }, colorpl[5] = { 0 }, pornpl = 0, sumpl = 0, onepairpl, twopairpl;
	int formco = 0, numco[20] = { 0 }, colorco[5] = { 0 }, pornco = 0, sumco = 0, onepairco, twopairco;
	int j;
	//===========================================================================玩家
	for (int i = 0; i < 7; i++)
	{
		if (wDeck[i].face == 1)
		{
			numpl[1]++;
		}
		if (wDeck[i].face == 2)
		{
			numpl[2]++;
		}
		if (wDeck[i].face == 3)
		{
			numpl[3]++;
		}
		if (wDeck[i].face ==4)
		{
			numpl[4]++;
		}
		if (wDeck[i].face == 5)
		{
			numpl[5]++;
		}
		if (wDeck[i].face == 6)
		{
			numpl[6]++;
		}
		if (wDeck[i].face == 7)
		{
			numpl[7]++;
		}
		if (wDeck[i].face == 8)
		{
			numpl[8]++;
		}
		if (wDeck[i].face == 9)
		{
			numpl[9]++;
		}
		if (wDeck[i].face == 10)
		{
			numpl[10]++;
		}
		if (wDeck[i].face == 11)
		{
			numpl[11]++;
		}
		if (wDeck[i].face == 12)
		{
			numpl[12]++;
		}
		if (wDeck[i].face == 13)
		{
			numpl[13]++;
		}

		if (!strcmp(wDeck[i].suit, "黑桃"))
		{
			colorpl[1] ++;
		}
		if (!strcmp(wDeck[i].suit, "紅心"))
		{
			colorpl[2]++;
		}
		if (!strcmp(wDeck[i].suit, "方塊"))
		{
			colorpl[3]++;
		}
		if (!strcmp(wDeck[i].suit, "梅花"))
		{
			colorpl[4]++;
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (numpl[i] == 2)
		{
			formpl = 1;//一對
			pornpl++;
		}
		if (pornpl >= 2)
		{
			formpl = 2;//兩對
		}
		if (numpl[i] == 3)
		{
			formpl = 3;//三條
			pornpl++;
		}
		if ((numpl[i] >= 1 && numpl[i + 1] >= 1 && numpl[i + 2] >= 1 && numpl[i + 3] >= 1 && numpl[i + 4] >= 1) ||( numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1))
		{
			formpl = 4;//順子
		}
	}
	for (j = 1; j <= 4; j++)
	{
		if (colorpl[j] >= 5)
		{
			formpl = 5;//同花
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (pornpl>=2)
		{
			formpl = 6;//葫蘆
		}
		if (numpl[i] == 4)
		{
			formpl = 7;//鐵支
		}
		if ((numpl[i] >= 1 && numpl[i + 1] >= 1 && numpl[i + 2] >= 1 && numpl[i + 3] >= 1 && numpl[i + 4] >= 1) || (numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1))
		{
			if ((!strcmp(wDeck[i].suit, wDeck[i + 1].suit)) && (!strcmp(wDeck[i].suit, wDeck[i + 2].suit)) && (!strcmp(wDeck[i].suit, wDeck[i + 3].suit)) && (!strcmp(wDeck[i].suit, wDeck[i + 4].suit)))
			{
				formpl = 8; //同花順
			}
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		printf("%d", numpl[i]);
	}

	//===========================================================================電腦
	for (int i = 2; i < 9; i++)
	{
		if (wDeck[i].face == 1)
		{
			numco[1]++;
		}
		if (wDeck[i].face == 2)
		{
			numco[2]++;
		}
		if (wDeck[i].face == 3)
		{
			numco[3]++;
		}
		if (wDeck[i].face == 4)
		{
			numco[4]++;
		}
		if (wDeck[i].face == 5)
		{
			numco[5]++;
		}
		if (wDeck[i].face == 6)
		{
			numco[6]++;
		}
		if (wDeck[i].face == 7)
		{
			numco[7]++;
		}
		if (wDeck[i].face ==8)
		{
			numco[8]++;
		}
		if (wDeck[i].face == 9)
		{
			numco[9]++;
		}
		if (wDeck[i].face == 10)
		{
			numco[10]++;
		}
		if (wDeck[i].face ==11)
		{
			numco[11]++;
		}
		if (wDeck[i].face == 12)
		{
			numco[12]++;
		}
		if (wDeck[i].face == 13)
		{
			numco[13]++;
		}

		if (!strcmp(wDeck[i].suit, "黑桃"))
		{
			colorco[1] ++;
		}
		if (!strcmp(wDeck[i].suit, "紅心"))
		{
			colorco[2]++;
		}
		if (!strcmp(wDeck[i].suit, "方塊"))
		{
			colorco[3]++;
		}
		if (!strcmp(wDeck[i].suit, "梅花"))
		{
			colorco[4]++;
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (numco[i] == 2)
		{
			formco = 1;//一對
			pornco++;
		}
		if (pornco >= 2)
		{
			formco = 2;//兩對
		}
		if (numco[i] == 3)
		{
			formco = 3;//三條
			pornco++;
		}
		if (numco[i] >= 1 && numco[i + 1] >= 1 && numco[i + 2] >= 1 && numco[i + 3] >= 1 && numco[i + 4] >= 1 || numco[10] >= 1 && numco[11] >= 1 && numco[12] >= 1 && numco[13] >= 1 && numco[1] >= 1)
		{
			formpl = 4;//順子
		}
	}
	for (j = 1; j <= 4; j++)
	{
		if (colorco[j] >= 5)
		{
			formco = 5;//同花
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (pornco >= 2)
		{
			formco = 6;//葫蘆
		}
		if (numco[i] == 4)
		{
			formco = 7;//鐵支
		}
	}
	
	
	//=========================================================================排型比較
	//return 1 玩家贏  
	//return 0 電腦贏
	//return 2 平手
	//=================================如果都是一對
	if (formco==1&&formpl==1)
	{
		for (int i = 2; i<= 13; i++)
		{
			if (numpl[i]==2)
			{
				onepairpl = i;
				numpl[i] = 0;
			}
			if (numco[i]==2)
			{
				onepairco = i;
				numco[i] = 0;
			}
		}
		if (numpl[1]==2)
		{
			onepairpl = 14;
		}
		if (numco[1] == 2)
		{
			onepairco = 14;
		}
		if (onepairco>onepairpl)
		{
			goto cw;
		}
		else if (onepairco < onepairpl)
		{
			goto pw;
		}
		else if (onepairco==onepairpl)
		{
			if (numpl[1] > numco[1])
			{
				goto pw;
			}
			else if (numpl[1] < numco[1])
			{
				goto cw;
			}
			else 
			{
				sumco += numco[1];
				sumpl += numpl[1];
			}
			for (int i = 13; i > 1; i--)
			{
				if (numpl[i] > numco[i])
				{
					goto pw;
				}
				else if (numpl[i] < numco[i])
				{
					goto cw;
				}
				sumco += numco[i];
				sumpl += numpl[i];
				if (sumco == 3 || sumpl == 3)
				{
					goto sh;
				}
			}
		}
	}
	//=================================如果都是兩對
	if (formco == 2 && formpl == 2)
	{
		if (numpl[1]==2&&numpl[1]>numco[1])
		{
			goto pw;
		}
		else if (numco[1] == 2 && numco[1] > numpl[1])
		{
			goto cw;
		}
		else
		{
			if (numco[1]==2&&numpl[1]==2)
			{
				for (int i = 13; i > 1; i--)
				{
					if (numpl[i] == 2 && numco[i] < numpl[i])
					{
						goto pw;
					}
					if (numco[i] == 2 && numco[i] > numpl[i])
					{
						goto cw;
					}
					if (numco[i] == 2&& numpl[i] == 2)
					{
						numco[i]-=2;
						numpl[i]-=2;
						numco[1]-=2;
						numpl[1] -= 2;
						for ( i = 13; i <1; i++)
						{
							if (numco[i]>numpl[i])
							{
								goto cw;
							}
							else if (numco[i] < numpl[i])
							{
								goto pw;
							}
							else
							{
								goto sh;
							}
						}
					}
				}
			}
			if (numco[1] != 2 && numpl[1] != 2)
			{
				for ( int i = 13; i >1; i--)
				{
					if (numco[i]==2&&numpl[i]<numco[i])
					{
						goto cw;
					}
					else if (numpl[i] == 2 && numpl[i] > numco[i])
					{
						goto pw;
					}
					else if (numpl[i] == 2&& numco[i] == 2)
					{
						numpl[i] = 0;
						numco[i] = 0;
						for  (int i = 13;  i >1;  i--)
						{
							if (numco[i] == 2 && numpl[i] < numco[i])
							{
								goto cw;
							}
							else if (numpl[i] == 2 && numpl[i] > numco[i])
							{
								goto pw;
							}
							else if (numpl[i] == 2 && numco[i] == 2)
							{
								numpl[i] = 0;
								numco[i] = 0;
								if (numpl[1] == 1&& numco[1] ==0 )
								{
									goto pw;
								}
								else if (numco[1] == 1 && numpl[1] == 0)
								{
									goto cw;
								}
								else if (numco[1] == 1 && numpl[1] == 1)
								{
									goto sh;
								}
								else
								{
									for (int i = 13; i > 1; i--)
									{

										if (numpl[i] < numco[i])
										{
											goto cw;
										}
										else if ( numpl[i] > numco[i])
										{
											goto pw;
										}
									}
									goto sh;
								}
								
							}
						}
					}
				}
			}
			
		}
		
	}
	//=================================如果都是三條
	if (formco==3&&formpl==3)
	{
		if (numco[1]==3&&numpl[1]<numco[1])
		{
			goto cw;
		}
		else if (numpl[1] == 3 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numpl[1] == 3 &&  numco[1]==3)
		{
			for (int i = 13; i > 1; i--)
			{
				if (numco[i]>numpl[i])
				{
					goto cw;
				}
				else if (numco[i] < numpl[i])
				{
					goto pw;
				}
				else if (numco[i] == numpl[i])
				{
					numco[i] = 0;
					numpl[i] = 0;
					for (int i = 13; i>1 ; i--)
					{
						if (numco[i] > numpl[i])
						{
							goto cw;
						}
						else if (numco[i] < numpl[i])
						{
							goto pw;
						}
						else if (numco[i] == numpl[i])
						{
							goto sh;
						}
					}
				}
			
			}

		}
	
		else
		{

			for (int i = 13; i > 1; i--)
			{
				if (numpl[i]==3&&numpl[i]>numco[i])
				{
					goto pw;
				}
				else if (numco[i] == 3 && numpl[i] < numco[i])
				{
					goto cw;
				}
				else if (numco[i] == 3 && numpl[i]==3)
				{
					numco[i] == 0;
					numpl[i] == 0;
					for (int i = 13; i > 1; i--)
					{
						if (numco[i] > numpl[i])
						{
							goto cw;
						}
						else if (numco[i] < numpl[i])
						{
							goto pw;
						}
						else if (numco[i] == numpl[i])
						{
							numco[i] = 0;

							numpl[i] = 0;
							for (int i = 13; i > 1; i--)
							{
								if (numco[i] > numpl[i])
								{
									goto cw;
								}
								else if (numco[i] < numpl[i])
								{
									goto pw;
								}
								else if (numco[i] == numpl[i])
								{
									goto sh;
								}
							}
						}

					}
				}
				
			}
		}
		
	}
	//=================================如果都是順子
	if (formco == 4 && formpl == 4)
	{
		if ((numco[10]>=1&&numco[11]>=1&&numco[12]>=1&&numco[13]>=1&&numco[1]>=1)&&(numpl[1]==0||numpl[10]==0||numpl[11]==0||numpl[12]==0||numpl[13]==0))
		{
			goto cw;
		}
		else if ((numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1) && (numco[1] == 0 || numco[10] == 0 || numco[11] == 0 || numco[12] == 0 || numco[13] == 0))
		{
			goto pw;
		}
		else if ((numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1) && (numco[1] >= 1 && numco[10]>=1 &&numco[11] >=1 &&numco[12] >=1 && numco[13] >=1))
		{
			goto sh;
		}
		else
		{
			for (int i = 13; i>=5; i--)
			{
				if ((numco[i] >= 1 && numco[i-1] >= 1 && numco[i-2] >= 1 && numco[i-3] >= 1 && numco[i-4] >= 1) && (numpl[i] == 0 || numpl[i-1] == 0 || numpl[i-2] == 0 || numpl[i-3] == 0 || numpl[i-4] == 0))
				{
					goto cw;
				}
				else if ((numpl[i] >= 1 && numpl[i - 1] >= 1 && numpl[i - 2] >= 1 && numpl[i - 3] >= 1 && numpl[i - 4] >= 1) && (numco[i] == 0 || numco[i - 1] == 0 || numco[i - 2] == 0 || numco[i - 3] == 0 || numco[i - 4] == 0))
				{
					goto pw;
				}
				else if ((numpl[i] >= 1 && numpl[i-1] >= 1 && numpl[i-2] >= 1 && numpl[i-3] >= 1 && numpl[i-4] >= 1) && (numco[i] >= 1 && numco[i-1] >= 1 && numco[i-2] >= 1 && numco[i-3] >= 1 && numco[i-4] >= 1))
				{
					goto sh;
				}
			}
		}
	}
	//=================================如果都是同花
	if (formco ==5 && formpl == 5)
	{
		if (colorpl[1]>=5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "黑桃"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorpl[2] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "紅心"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorpl[3] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "方塊"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorpl[4] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "梅花"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		if (colorco[1] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "黑桃"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorco[2] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "紅心"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorco[3] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "方塊"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorco[4] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "梅花"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		if (numpl[1]>numco[1])
		{
			goto pw;
		}
		else if (numpl[1] < numco[1])
		{
			goto cw;
		}
		else
		{
			for (int i = 13; i >=2; i--)
			{
				if (numpl[i] < numco[i])
				{
					goto pw;
				}
				else if (numpl[i] > numco[i])
				{
					goto cw;
				}
			}
			goto sh;
		}
	}
	//=================================如果都是葫蘆
	if (formco == 6 && formpl == 6)
	{
		if (numco[1]==3 && numpl[1]<numco[1])
		{
			goto cw;
		}
		else if (numpl[1] == 3 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numpl[1] == 3 && numco[1] == 3)
		{
			for  (int i = 13;  i >=2;  i--)
			{
				if (numco[i]>=2 && 2>numpl[i])
				{
					goto cw;
				}
				else if (numpl[i] >= 2 && numco[i] < 2)
				{
					goto pw;
				}
				else if (numpl[i] >= 2 && numco[i] >= 2)
				{
					goto sh;
				}
			}
		}
		else if (numco[1]<3&&numpl[1]<3)
		{
			for (int i = 13; i >= 2 ; i--)
			{
				if (numco[i]==3&&numpl[i]<numco[i])
				{
					goto cw;
				}
				else if (numpl[i] == 3 && numco[i] < numpl[i])
				{
					goto pw;
				}
				else if (numpl[i] == 3&& numco[i] == 3)
				{
					if (numco[1]==2&&numco[1]>numpl[1])
					{
						goto cw;
					}
					if (numpl[1] == 2 && numco[1] < numpl[1])
					{
						goto pw;
					}
					if (numpl[1]==2&&numco[1]==2)
					{
						goto sh;
					}
					if (numpl[1]<2 &&numco[1]<2)
					{
						for (int i = 13; i >= 2; i--)
						{
							if (numpl[i] >= 2 && numco[i] < numpl[i])
							{
								goto pw;
							}
							else if (numco[i] >= 2 && numco[i] > numpl[i])
							{
								goto cw;
							}
							else if (numco[i] >= 2 && numpl[i]>=2)
							{
								goto sh;
							}
						}

					}
				}
			}
		}
	}
	//=================================如果都是鐵支
	if (formco == 7 && formpl == 7)
	{
		if (numco[1]==4&&numpl[1]<numco[1])
		{
			goto cw;
		}
		else if (numpl[1] == 4 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numpl[1]==4&&numco[1]==4)
		{
			for (int i = 13; i >= 2; i--)
			{
				if (numco[i]>0&&numpl[i]==0)
				{
					goto cw;
				}
				else if (numpl[i] > 0 && numco[i] == 0)
				{
					goto pw;
				}
				else if (numpl[i] > 0&&numco[i]>0)
				{
					goto sh;
				}
			}
		}
		else if (numpl[1]<4&&numco[1]<4)
		{
			if (numpl[1]>0&&numco[1]==0)
			{
				goto pw;
			}
			else if (numco[1] > 0 && numpl[1] == 0)
			{
				goto cw;
			}
			else if (numco[1] == 0 && numpl[1] == 0)
			{
				for (int i = 13; i >= 2; i--)
				{
					if (numco[i]==4&&numpl[i]<numco[i])
					{
						goto cw;
					}
					else if (numpl[i] == 4 && numco[i] < numpl[i])
					{
						goto pw;
					}
					else if (numpl[i] == 4&& numco[i] == 4)
					{
						for (int i = 13; i >=2 ; i--)
						{
							if (numco[i]>0&&numpl[i]<numco[i])
							{
								goto cw;
							}
							else if (numpl[i] > 0 && numpl[i] > numco[i])
							{
								goto pw;
							}
							else if (numpl[i]>0&&numco[i]>0)
							{
								goto sh;
							}
						}
					}
				}
			}
		}

	}
cw:
	return 0;
pw:
	return 1;
sh:
	return 2;
}


/* place strings into Card structures */
void fillDeck(Card * const wDeck, const char * wFace[],
	const char * wSuit[])
{
	int i;/* counter */

	/* loop through wDeck */
	for (i = 0; i <= 51; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}/* end for */
}/* end function fillDeck */

/* shuffle cards */
void shuffle(Card * const wDeck)
{
	int i;/* counter */
	int j;/* variable to hold random value between 0 - 51 */
	Card temp; /* define temporary structure for swapping Cards */

	/* loop through wDeck randomly swapping Cards */
	for (i = 0; i <= 51; i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}/* end for */
}/* end function shuffle */

/* deal cards */
void deal(const Card * const wDeck)
{
	int i;/* counter */
	/* loop through wDeck */
	for (i = 0; i <= 51; i++) {
		printf("%s%-5d%s", wDeck[i].suit, wDeck[i].face,
			(i + 1) % 4 ? " " : "\n");
	}/* end for */
}/* end function deal */
