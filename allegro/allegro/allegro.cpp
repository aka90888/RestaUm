#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>

#define LARGURA 700
#define ALTURA 700

typedef struct p {
	int x1, x2;
	int y1, y2;
	int N;
}TPeca;

typedef struct tab {
	int x1, x2;
	int y1, y2;
	int status;
}TTab;

typedef struct verificar {
	int i1, j1;
	int i2, j2;
	int i3, j3;
}TVerif;

void verificar(TVerif v, TPeca peca[7][7], TTab tab[7][7]) {//verifico e ajusto
	int ok = 0;
	if (peca[v.i1][v.j1].N + 1 == peca[v.i2][v.j2].N && peca[v.i1][v.j1].N + 2 == peca[v.i3][v.j3].N && tab[v.i3][v.j3].status == 2) {//dir
		tab[v.i1][v.j1].status = 2;
		tab[v.i2][v.j2].status = 2;
		tab[v.i3][v.j3].status = 1;

		al_draw_filled_circle(tab[v.i1][v.j1].x2 - 50, tab[v.i1][v.j1].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i2][v.j2].x2 - 50, tab[v.i2][v.j2].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i3][v.j3].x2 - 50, tab[v.i3][v.j3].y2 - 50, 25, al_map_rgb(0, 0, 0));
	}
	else if (peca[v.i1][v.j1].N - 1 == peca[v.i2][v.j2].N && peca[v.i1][v.j1].N - 2 == peca[v.i3][v.j3].N && tab[v.i3][v.j3].status == 2) {//esq
		tab[v.i1][v.j1].status = 2;
		tab[v.i2][v.j2].status = 2;
		tab[v.i3][v.j3].status = 1;

		al_draw_filled_circle(tab[v.i1][v.j1].x2 - 50, tab[v.i1][v.j1].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i2][v.j2].x2 - 50, tab[v.i2][v.j2].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i3][v.j3].x2 - 50, tab[v.i3][v.j3].y2 - 50, 25, al_map_rgb(0, 0, 0));
	}
	else if (peca[v.i1][v.j1].N - 7 == peca[v.i2][v.j2].N && peca[v.i1][v.j1].N - 14 == peca[v.i3][v.j3].N && tab[v.i3][v.j3].status == 2) {
		tab[v.i1][v.j1].status = 2;
		tab[v.i2][v.j2].status = 2;
		tab[v.i3][v.j3].status = 1;

		al_draw_filled_circle(tab[v.i1][v.j1].x2 - 50, tab[v.i1][v.j1].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i2][v.j2].x2 - 50, tab[v.i2][v.j2].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i3][v.j3].x2 - 50, tab[v.i3][v.j3].y2 - 50, 25, al_map_rgb(0, 0, 0));
	}
	else if (peca[v.i1][v.j1].N + 7 == peca[v.i2][v.j2].N && peca[v.i1][v.j1].N + 14 == peca[v.i3][v.j3].N && tab[v.i3][v.j3].status == 2) {
		tab[v.i1][v.j1].status = 2;
		tab[v.i2][v.j2].status = 2;
		tab[v.i3][v.j3].status = 1;

		al_draw_filled_circle(tab[v.i1][v.j1].x2 - 50, tab[v.i1][v.j1].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i2][v.j2].x2 - 50, tab[v.i2][v.j2].y2 - 50, 25, al_map_rgb(255, 255, 255));
		al_draw_filled_circle(tab[v.i3][v.j3].x2 - 50, tab[v.i3][v.j3].y2 - 50, 25, al_map_rgb(0, 0, 0));
	}
	else {
		system("cls");
		printf("Jogada Invalida \n");
	}
}

int main() {
	int ganhou = 0;
	int flag = 0;
	int N = 1, num = 1;
	int i, j;
	int fim = 0;
	int area = 0;
	TTab tab[7][7];
	TPeca peca[7][7];
	TVerif v;

	int x1 = 0, x2 = 100;
	int y1 = 0, y2 = 100;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			tab[i][j].x1 = x1;
			tab[i][j].x2 = x2;

			tab[i][j].y1 = y1;
			tab[i][j].y2 = y2;

			tab[i][j].status = 1;

			x1 = x2;
			x2 = x2 + 100;
		}
		x1 = 0;
		x2 = 100;

		y1 = y2;
		y2 = y2 + 100;
	}
	tab[3][3].status = 2;

	tab[0][0].status = 0;
	tab[0][1].status = 0;
	tab[1][0].status = 0;
	tab[1][1].status = 0;

	tab[0][5].status = 0;
	tab[0][6].status = 0;
	tab[1][5].status = 0;
	tab[1][6].status = 0;

	tab[5][0].status = 0;
	tab[5][1].status = 0;
	tab[6][0].status = 0;
	tab[6][1].status = 0;

	tab[5][5].status = 0;
	tab[5][6].status = 0;
	tab[6][5].status = 0;
	tab[6][6].status = 0;

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_BITMAP *tabuleiro = NULL;
	ALLEGRO_EVENT_QUEUE *fila = NULL;

	al_init();

	//addons
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();

	janela = al_create_display(LARGURA, ALTURA);
	al_set_window_title(janela, "Jogo Resta Um");
	al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	tabuleiro = al_load_bitmap("tabuleiro.bmp");
	al_draw_bitmap(tabuleiro, 0, 0, 0);

	//alocar as pecas
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (tab[i][j].status == 1) {
				al_draw_filled_circle(tab[i][j].x2 - 50, tab[i][j].y2 - 50, 25, al_map_rgb(0, 0, 0));

				peca[i][j].x1 = tab[i][j].x2 - 80; //50x50 cada peca, dentro da area 100x100
				peca[i][j].x2 = peca[i][j].x1 + 60;

				peca[i][j].y1 = tab[i][j].y2 - 80;
				peca[i][j].y2 = peca[i][j].y1 + 60;

				peca[i][j].N = N;
				N++;
				}
			else {
				peca[i][j].x1 = tab[i][j].x2 - 80; //50x50 cada peca, dentro da area 100x100
				peca[i][j].x2 = peca[i][j].x1 + 60;

				peca[i][j].y1 = tab[i][j].y2 - 80;
				peca[i][j].y2 = peca[i][j].y1 + 60;

				peca[i][j].N = N;
				N++;
			}
		}
	}

	//fila
	fila = al_create_event_queue();

	//eventos
	al_register_event_source(fila, al_get_keyboard_event_source());
	al_register_event_source(fila, al_get_mouse_event_source());

	while (!fim) {
		ALLEGRO_EVENT evento;

		al_wait_for_event(fila, &evento);

		if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				fim = 1;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
			for (i = 0; i < 7; i++) {
				for (j = 0; j < 7; j++) {
					if (evento.mouse.x >= peca[i][j].x1 && evento.mouse.x <= peca[i][j].x2 &&
						evento.mouse.y >= peca[i][j].y1 && evento.mouse.y <= peca[i][j].y2) {
						if (tab[i][j].status != 0) {
							area = 1;
							break;
						}
					}
					else {
						area = 0;
					}
				}
				if (area == 1) {
					break;
				}
			}
		}

		//ao passar o mouse por cima da peca
		if (area == 1) {
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				if (evento.mouse.button & 1) {//esquerdo
					flag++;
					printf("[%d]", flag);
					if (flag == 1) {
						v.i1 = i;
						v.j1 = j;
					}
					else if (flag == 2) {
						v.i2 = i;
						v.j2 = j;
					}
					else if (flag == 3) {
						v.i3 = i;
						v.j3 = j;

						system("cls");

						verificar(v, peca, tab);

						flag = 0;
					}
				}
			}
		}

		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (evento.mouse.button & 2) {//direito
				system("cls");
				flag = 0;
			}
		}
		
		ganhou = 0;
		for (int ii = 0; ii < 7; ii++) {
			for (int jj = 0; jj < 7; jj++) {
				if (tab[ii][jj].status == 1) {
					ganhou++;
				}
			}
		}
		if (ganhou == 1) {
			printf("Ganhou!!!");
			fim = 1;
		}
		

		al_flip_display();
	}

	//free

	return 0;
}