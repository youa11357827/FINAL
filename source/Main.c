#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct card
{
	char* face;
	char* suit;
}card;
int  init_Bet();
void show(int i, int f, card* const wDeck);
void start(const card* const wDeck, int *z);
void shuffle(card* const wDeck);
void fillDeck(card  *wDeck, const char* wFace[], const char* wSuit[]);
int compare(card  *wDeck);
/* prototypes */
int gold = 2000;
int opmoney = 2000;
int tablemoney = 0;
int main()
{
	int z = 0;
	card  deck[52];
	char choose[10];
	const int face[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	const char *suit[] = { "����","���","����","�®�" };
	srand(time(NULL));
	fillDeck(deck, face, suit);
	printf("�O�_�n�}�l�s�ɧ�(y/n)\n");
	scanf_s("%s", choose, sizeof(choose));
	while (!strcmp(choose, "y"))
	{
		shuffle(deck);
		start(deck, &z);
		printf("�O�_�n�}�l�s�ɧ�(y/n)\n");
		scanf_s("%s", choose, sizeof(choose));
	}
	system("pause");
	return 0;
}


void start(const card* const wDeck, int *z)
{
	int i;
	printf("\n�z��W���P:");
	show(0, 1, wDeck);
	int con = init_Bet();
	if (con == -1)
	{
		return;
	}
	printf("\n\n\n\n");
	//==================================================================�Ĥ@�^�X����
	if (con != 4)
	{
		printf("\n\n�z��W���P:");
		show(0, 1, wDeck);
		printf("\n���W���P:");
		show(2, 4, wDeck);
		printf("\n\n\n\n");
		con = init_Bet();
		if (con == -1)
		{
			return;
		}
	}
	//==================================================================�ĤG�^�X����
	if (con != 4)
	{
		printf("\n\n�z��W���P:");
		show(0, 1, wDeck);
		printf("\n���W���P:");
		show(2, 5, wDeck);
		printf("\n\n\n\n");
		con = init_Bet();
		if (con == -1)
		{
			return;
		}
	}
	//==================================================================�ĤT�^�X����
	printf("\n\n\n\n");
	if (con == -1)
	{
		return;
	}
	con = compare(wDeck);
	printf("\n���W���P:");
	show(2, 6, wDeck);
	printf("\n\n�z��W���P:");
	show(0, 1, wDeck);
	printf("\n\n����W���P:");
	show(7, 8, wDeck);
	if (con == 1)
	{
		printf("���a���\n");
		gold = gold + tablemoney;
		if (opmoney == 0)
		{
			printf("�q���}��\n");
			system("pause");
			exit(0);
		}
		tablemoney = 0;
		return;
	}
	if (con == 0)
	{
		printf("�q�����\n");
		opmoney = opmoney + tablemoney;
		if (gold == 0)
		{
			printf("�z����ǤF\n");
			system("pause");
			exit(0);
		}
		tablemoney = 0;
		return;
	}
	if (con == 2)
	{
		gold = gold + (tablemoney / 2);
		opmoney = opmoney + (tablemoney / 2);
		tablemoney = 0;
		printf("����\n");
		return;
	}
	printf("\n\n\n\n");


	//==================================================================�ĥ|�^�X����
}
void show(int i, int f, card* const wDeck)
{
	for (int j = i; j <= f; j++)
	{
		printf("%s%-5d", wDeck[j].suit, wDeck[j].face);
	}
	printf("\n");
}
int init_Bet()
{
	int i = 0;
	char select[10] = "";
	int amount = 0, Basic, react;
	srand(time(NULL));
	Basic = 1 + rand() % 50;
	react = rand() % 10;
	//printf("�ﭱ���a�U��`%d", Basic);
	printf("\n�O�_��P?(y/n)\n");
	scanf_s("%s", select, sizeof(char) * 4);
	if (!strcmp(select, "n"))
	{
		printf("�q���{�b��:%d��\n", opmoney);
		printf("�{�b�ڦ�:%d��\n", gold);
		printf("�ФU��`\n");
		scanf_s("%d", &Basic);
		while (Basic > gold)
		{
			printf("�A�S�����a��\n�Э��s�U�`:");
			scanf_s("%d", &Basic);
		}
		if (react == 0)
		{
			printf("��⤣�Q��A��\n");
			printf("return the game");
			return -1;
		}
		else
		{
			printf("����`\n");
			tablemoney = tablemoney + Basic * 2;
			gold = gold - Basic;
			opmoney = opmoney - Basic;
			if (gold == 0)
			{
				printf("���U!!!!!!!!");
				printf("�i���W�����B: 4000\n");
				return 4;
			}
			if (gold < 0)
			{
				printf("�}���F!!!!!!!!!");
				return -1;
			}
			printf("�q���{�b��:%d��\n", opmoney);
			printf("�z�Ѿl���w�X:%d\n", gold);
			printf("�i���W�����B;%d\n", tablemoney);
			printf("\n�O�_�[�`?(y/n)\n");
			scanf_s("%s", select, sizeof(char) * 4);
			if (!strcmp(select, "y"))
			{
				printf("�[�`�h��\n?");
				scanf_s("%d", &amount);
				while (amount > gold)
				{
					printf("�A�S�����a��\n�Э��s�U�`:");
					scanf_s("%d", &amount);
				}
				{
					if (react == 0)
					{
						printf("����P\n");
						gold = gold + amount + Basic * 2;
						printf("�q���{�b��:%d��\n", opmoney);
						printf("�z�Ѿl���w�X:%d", gold);
						printf("return the game");
						return -1;
					}
					else
					{
						printf("����`\n");
						tablemoney = tablemoney + amount * 2;
						gold = gold - amount;
						opmoney = opmoney - amount;
						printf("�Ѿl���w�X:%d\n", gold);
						printf("�q���{�b��:%d��\n", opmoney);
						printf("�i���W�����B;%d\n", tablemoney);

						if (gold == 0)
						{
							printf("���U!!!!!!!!");
							printf("�i���W�����B: 4000\n");

							return 3;
						}
						if (gold < 0)
						{
							printf("�}���F!!!!!!!!!");
							return -1;
						}
					}
				}
			}
			else
			{
				return 3;
			}
		}
	}
	else
	{
		opmoney = opmoney + tablemoney;
		tablemoney = 0;
		return -1;
	}
}
int compare(card  *wDeck)
{
	int formpl = 0, numpl[20] = { 0 }, colorpl[5] = { 0 }, pornplFH = 0, pornplOP = 0, sumpl = 0, onepairpl, twopairpl, SFnumpl[20] = { 0 };
	int formco = 0, numco[20] = { 0 }, colorco[5] = { 0 }, porncoFH = 0, porncoOP = 0, sumco = 0, onepairco, twopairco, SFnumco[20] = { 0 };
	int j, hole, juice, huge, dick, ass;
	//===========================================================================���a
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
		if (wDeck[i].face == 4)
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

		if (!strcmp(wDeck[i].suit, "�®�"))
		{
			colorpl[1] ++;
		}
		if (!strcmp(wDeck[i].suit, "����"))
		{
			colorpl[2]++;
		}
		if (!strcmp(wDeck[i].suit, "���"))
		{
			colorpl[3]++;
		}
		if (!strcmp(wDeck[i].suit, "����"))
		{
			colorpl[4]++;
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (numpl[i] == 2)
		{
			formpl = 1;//�@��
			pornplOP++;
		}
		if (pornplOP >= 2)
		{
			formpl = 2;//���
		}
		if (numpl[i] == 3)
		{
			formpl = 3;//�T��
			pornplFH++;
		}
		if ((numpl[i] >= 1 && numpl[i + 1] >= 1 && numpl[i + 2] >= 1 && numpl[i + 3] >= 1 && numpl[i + 4] >= 1) || (numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1))
		{
			formpl = 4;//���l
		}
	}
	for (j = 1; j <= 4; j++)
	{
		if (colorpl[j] >= 5)
		{
			formpl = 5;//�P��
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (pornplOP >= 1 && pornplFH >= 1)
		{
			formpl = 6;//��Ī
		}
		if (numpl[i] == 4)
		{
			formpl = 7;//�K��
		}
	}
	printf("���a ");
	if (formpl == 0)
	{
		printf("���P\n");
	}
	if (formpl == 1)
	{
		printf("�@��\n");
	}
	if (formpl == 2)
	{
		printf("�G��\n");
	}
	if (formpl == 3)
	{
		printf("�T��\n");
	}
	if (formpl == 4)
	{
		printf("���l\n");
	}
	if (formpl == 5)
	{
		printf("�P��\n");
	}
	if (formpl == 6)
	{
		printf("��Ī\n");
	}
	if (formpl == 7)
	{
		printf("�K��\n");
	}
	if (formpl == 8)
	{
		printf("�P�ᶶ\n");
	}
	for (int i = 1; i < 20; i++)
	{
		SFnumpl[i] = numpl[i];
	}
	for (int i = 0; i <= 6; i++)
	{
		if (colorpl[1] >= 5)
		{
			if (strcmp(wDeck[i].suit, "�®�"))
			{
				SFnumpl[*wDeck[i].face] --;
			}
		}
		if (colorpl[2] >= 5)
		{
			if (strcmp(wDeck[i].suit, "����"))
			{
				SFnumpl[*wDeck[i].face] --;
			}
		}
		if (colorpl[3] >= 5)
		{
			if (strcmp(wDeck[i].suit, "���"))
			{
				SFnumpl[*wDeck[i].face] --;
			}
		}
		if (colorpl[4] >= 5)
		{
			if (strcmp(wDeck[i].suit, "����"))
			{
				SFnumpl[*wDeck[i].face] --;
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (SFnumpl[i] >= 1 && SFnumpl[i + 1] >= 1 && SFnumpl[i + 2] >= 1 && SFnumpl[i + 3] >= 1 && SFnumpl[i + 4] >= 1)
		{
			formpl = 8;//�P�ᶶ
		}
	}
	if (SFnumpl[1] >= 1 && SFnumpl[10] >= 1 && SFnumpl[11] >= 1 && SFnumpl[12] >= 1 && SFnumpl[13] >= 1)
	{
		formpl = 9;//�P��j��
	}
	//===========================================================================�q��
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
		if (wDeck[i].face == 8)
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
		if (wDeck[i].face == 11)
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

		if (!strcmp(wDeck[i].suit, "�®�"))
		{
			colorco[1] ++;
		}
		if (!strcmp(wDeck[i].suit, "����"))
		{
			colorco[2]++;
		}
		if (!strcmp(wDeck[i].suit, "���"))
		{
			colorco[3]++;
		}
		if (!strcmp(wDeck[i].suit, "����"))
		{
			colorco[4]++;
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (numco[i] == 2)
		{
			formco = 1;//�@��
			porncoOP++;
		}
		if (porncoOP >= 2)
		{
			formco = 2;//���
		}
		if (numco[i] == 3)
		{
			formco = 3;//�T��
			porncoFH++;
		}
		if ((numco[i] >= 1 && numco[i + 1] >= 1 && numco[i + 2] >= 1 && numco[i + 3] >= 1 && numco[i + 4] >= 1) || (numco[10] >= 1 && numco[11] >= 1 && numco[12] >= 1 && numco[13] >= 1 && numco[1] >= 1))
		{
			formpl = 4;//���l
		}
	}
	for (j = 1; j <= 4; j++)
	{
		if (colorco[j] >= 5)
		{
			formco = 5;//�P��
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (porncoOP >= 1 && porncoFH >= 1)
		{
			formco = 6;//��Ī
		}
		if (numco[i] == 4)
		{
			formco = 7;//�K��
		}
	}
	printf("�q�� ");
	if (formco == 0)
	{
		printf("���P\n");
	}
	if (formco == 1)
	{
		printf("�@��\n");
	}
	if (formco == 2)
	{
		printf("�G��\n");
	}
	if (formco == 3)
	{
		printf("�T��\n");
	}
	if (formco == 4)
	{
		printf("���l\n");
	}
	if (formco == 5)
	{
		printf("�P��\n");
	}
	if (formco == 6)
	{
		printf("��Ī\n");
	}
	if (formco == 7)
	{
		printf("�K��\n");
	}
	if (formco == 8)
	{
		printf("�P�ᶶ\n");
	}
	for (int i = 1; i < 20; i++)
	{
		SFnumco[i] = numco[i];
	}
	for (int i = 2; i <= 8; i++)
	{
		if (colorco[1] >= 5)
		{
			if (strcmp(wDeck[i].suit, "�®�"))
			{
				SFnumco[*wDeck[i].face] --;
			}
		}
		if (colorco[2] >= 5)
		{
			if (strcmp(wDeck[i].suit, "����"))
			{
				SFnumco[*wDeck[i].face] --;
			}
		}
		if (colorco[3] >= 5)
		{
			if (strcmp(wDeck[i].suit, "���"))
			{
				SFnumco[*wDeck[i].face] --;
			}
		}
		if (colorco[4] >= 5)
		{
			if (strcmp(wDeck[i].suit, "����"))
			{
				SFnumco[*wDeck[i].face] --;
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (SFnumco[i] >= 1 && SFnumco[i + 1] >= 1 && SFnumco[i + 2] >= 1 && SFnumco[i + 3] >= 1 && SFnumco[i + 4] >= 1)
		{
			formco = 8;//�P�ᶶ
		}
	}
	if (SFnumco[1] >= 1 && SFnumco[10] >= 1 && SFnumco[11] >= 1 && SFnumco[12] >= 1 && SFnumco[13] >= 1)
	{
		formpl = 9;//�P��j��
	}

	//=========================================================================�ƫ����
	if (formpl > formco)
	{
		goto pw;
	}
	else if (formco < formco)
	{
		goto cw;
	}
	//return 1 ���aĹ  
	//return 0 �q��Ĺ
	//return 2 ����
	//=================================�p�G���O�@��
	if (formco == 1 && formpl == 1)
	{
		for (int i = 2; i <= 13; i++)
		{
			if (numpl[i] == 2)
			{
				onepairpl = i;
				numpl[i] = 0;
			}
			if (numco[i] == 2)
			{
				onepairco = i;
				numco[i] = 0;
			}
		}
		if (numpl[1] == 2)
		{
			onepairpl = 14;
		}
		if (numco[1] == 2)
		{
			onepairco = 14;
		}
		if (onepairco > onepairpl)
		{
			goto cw;
		}
		else if (onepairco < onepairpl)
		{
			goto pw;
		}
		else if (onepairco == onepairpl)
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
	//=================================�p�G���O���
	if (formco == 2 && formpl == 2)
	{
		if (numpl[1] == 2 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numco[1] == 2 && numco[1] > numpl[1])
		{
			goto cw;
		}
		else
		{
			if (numco[1] == 2 && numpl[1] == 2)
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
					if (numco[i] == 2 && numpl[i] == 2)
					{
						numco[i] -= 2;
						numpl[i] -= 2;
						numco[1] -= 2;
						numpl[1] -= 2;
						for (i = 13; i < 1; i++)
						{
							if (numco[i] > numpl[i])
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
				for (int i = 13; i > 1; i--)
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
						for (int i = 13; i > 1; i--)
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
								if (numpl[1] == 1 && numco[1] == 0)
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
										else if (numpl[i] > numco[i])
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
	//=================================�p�G���O�T��
	if (formco == 3 && formpl == 3)
	{
		if (numco[1] == 3 && numpl[1] < numco[1])
		{
			goto cw;
		}
		else if (numpl[1] == 3 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numpl[1] == 3 && numco[1] == 3)
		{
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
		else
		{

			for (int i = 13; i > 1; i--)
			{
				if (numpl[i] == 3 && numpl[i] > numco[i])
				{
					goto pw;
				}
				else if (numco[i] == 3 && numpl[i] < numco[i])
				{
					goto cw;
				}
				else if (numco[i] == 3 && numpl[i] == 3)
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
	//=================================�p�G���O���l
	if (formco == 4 && formpl == 4)
	{
		if ((numco[10] >= 1 && numco[11] >= 1 && numco[12] >= 1 && numco[13] >= 1 && numco[1] >= 1) && (numpl[1] == 0 || numpl[10] == 0 || numpl[11] == 0 || numpl[12] == 0 || numpl[13] == 0))
		{
			goto cw;
		}
		else if ((numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1) && (numco[1] == 0 || numco[10] == 0 || numco[11] == 0 || numco[12] == 0 || numco[13] == 0))
		{
			goto pw;
		}
		else if ((numpl[10] >= 1 && numpl[11] >= 1 && numpl[12] >= 1 && numpl[13] >= 1 && numpl[1] >= 1) && (numco[1] >= 1 && numco[10] >= 1 && numco[11] >= 1 && numco[12] >= 1 && numco[13] >= 1))
		{
			goto sh;
		}
		else
		{
			for (int i = 13; i >= 5; i--)
			{
				if ((numco[i] >= 1 && numco[i - 1] >= 1 && numco[i - 2] >= 1 && numco[i - 3] >= 1 && numco[i - 4] >= 1) && (numpl[i] == 0 || numpl[i - 1] == 0 || numpl[i - 2] == 0 || numpl[i - 3] == 0 || numpl[i - 4] == 0))
				{
					goto cw;
				}
				else if ((numpl[i] >= 1 && numpl[i - 1] >= 1 && numpl[i - 2] >= 1 && numpl[i - 3] >= 1 && numpl[i - 4] >= 1) && (numco[i] == 0 || numco[i - 1] == 0 || numco[i - 2] == 0 || numco[i - 3] == 0 || numco[i - 4] == 0))
				{
					goto pw;
				}
				else if ((numpl[i] >= 1 && numpl[i - 1] >= 1 && numpl[i - 2] >= 1 && numpl[i - 3] >= 1 && numpl[i - 4] >= 1) && (numco[i] >= 1 && numco[i - 1] >= 1 && numco[i - 2] >= 1 && numco[i - 3] >= 1 && numco[i - 4] >= 1))
				{
					goto sh;
				}
			}
		}
	}
	//=================================�p�G���O�P��
	if (formco == 5 && formpl == 5)
	{
		if (colorpl[1] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "�®�"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorpl[2] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "����"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorpl[3] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "���"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorpl[4] >= 5)
		{
			for (int i = 0; i <= 6; i++)
			{
				if (strcmp(wDeck[i].suit, "����"))
				{
					numpl[*wDeck[i].face] = 0;
				}
			}
		}
		if (colorco[1] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "�®�"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorco[2] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "����"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorco[3] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "���"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
		else if (colorco[4] >= 5)
		{
			for (int i = 2; i <= 8; i++)
			{
				if (strcmp(wDeck[i].suit, "����"))
				{
					numco[*wDeck[i].face] = 0;
				}
			}
		}
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
			for (int i = 13; i >= 2; i--)
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
	//=================================�p�G���O��Ī
	if (formco == 6 && formpl == 6)
	{
		if (numco[1] == 3 && numpl[1] < numco[1])
		{
			goto cw;
		}
		else if (numpl[1] == 3 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numpl[1] == 3 && numco[1] == 3)
		{
			for (int i = 13; i >= 2; i--)
			{
				if (numco[i] >= 2 && 2 > numpl[i])
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
		else if (numco[1] < 3 && numpl[1] < 3)
		{
			for (int i = 13; i >= 2; i--)
			{
				if (numco[i] == 3 && numpl[i] < numco[i])
				{
					goto cw;
				}
				else if (numpl[i] == 3 && numco[i] < numpl[i])
				{
					goto pw;
				}
				else if (numpl[i] == 3 && numco[i] == 3)
				{
					if (numco[1] == 2 && numco[1] > numpl[1])
					{
						goto cw;
					}
					if (numpl[1] == 2 && numco[1] < numpl[1])
					{
						goto pw;
					}
					if (numpl[1] == 2 && numco[1] == 2)
					{
						goto sh;
					}
					if (numpl[1] < 2 && numco[1] < 2)
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
							else if (numco[i] >= 2 && numpl[i] >= 2)
							{
								goto sh;
							}
						}

					}
				}
			}
		}
	}
	//=================================�p�G���O�K��
	if (formco == 7 && formpl == 7)
	{
		if (numco[1] == 4 && numpl[1] < numco[1])
		{
			goto cw;
		}
		else if (numpl[1] == 4 && numpl[1] > numco[1])
		{
			goto pw;
		}
		else if (numpl[1] == 4 && numco[1] == 4)
		{
			for (int i = 13; i >= 2; i--)
			{
				if (numco[i] > 0 && numpl[i] == 0)
				{
					goto cw;
				}
				else if (numpl[i] > 0 && numco[i] == 0)
				{
					goto pw;
				}
				else if (numpl[i] > 0 && numco[i] > 0)
				{
					goto sh;
				}
			}
		}
		else if (numpl[1] < 4 && numco[1] < 4)
		{
			if (numpl[1] > 0 && numco[1] == 0)
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
					if (numco[i] == 4 && numpl[i] < numco[i])
					{
						goto cw;
					}
					else if (numpl[i] == 4 && numco[i] < numpl[i])
					{
						goto pw;
					}
					else if (numpl[i] == 4 && numco[i] == 4)
					{
						for (int i = 13; i >= 2; i--)
						{
							if (numco[i] > 0 && numpl[i] < numco[i])
							{
								goto cw;
							}
							else if (numpl[i] > 0 && numpl[i] > numco[i])
							{
								goto pw;
							}
							else if (numpl[i] > 0 && numco[i] > 0)
							{
								goto sh;
							}
						}
					}
				}
			}
		}

	}
	//=================================�p�G���O�P�ᶶ
	if (formco == 8 && formpl == 8)
	{
		for (int i = 13; i >= 5; i++)
		{
			if (SFnumco[i] > SFnumpl[i] && SFnumco[i] >= 1 && SFnumco[i - 1] >= 1 && SFnumco[i - 2] >= 1 && SFnumco[i - 3] >= 1 && SFnumco[i - 4] >= 1)
			{
				goto cw;
			}
			else if (SFnumco[i] < SFnumpl[i] && SFnumpl[i] >= 1 && SFnumpl[i - 1] >= 1 && SFnumpl[i - 2] >= 1 && SFnumpl[i - 3] >= 1 && SFnumpl[i - 4] >= 1)
			{
				goto pw;
			}
			else if (SFnumco[i] >= 1 && SFnumco[i - 1] >= 1 && SFnumco[i - 2] >= 1 && SFnumco[i - 3] >= 1 && SFnumco[i - 4] >= 1 && SFnumpl[i] >= 1 && SFnumpl[i - 1] >= 1 && SFnumpl[i - 2] >= 1 && SFnumpl[i - 3] >= 1 && SFnumpl[i - 4] >= 1)
			{
				goto sh;
			}
		}
	}
	//=================================�p�G���O�P��j��
	if (formco == 9 && formpl == 9)
	{
		goto sh;
	}
cw:
	return 0;
pw:
	return 1;
sh:
	return 2;
}
/* place strings into Card structures */
void shuffle(card* const wDeck)
{
	int j;
	card temp;
	for (int i = 0; i < 52; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}
void fillDeck(card  *wDeck, const char* wFace[], const char* wSuit[])
{
	int i;
	for (i = 0; i < 52; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}