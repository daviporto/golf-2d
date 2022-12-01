#include "Level.h"
void Level::Dim_Moves() {
	this->Remaining_Moves--;
}
int Level::Get_Remaining_Moves() {
	return this->Remaining_Moves;
}
double Level::Get_Time() {
	return this->Time;
}
double Level::Get_pos_ball_init_x() {
	return this->pos_ball_init_x;
}
double Level::Get_pos_ball_init_y() {
	return this->pos_ball_init_y;
}
double Level::Get_pos_hole_init_x() {
	return this->pos_hole_init_x;
}
double Level::Get_pos_hole_init_y() {
	return this->pos_hole_init_y;
}
void Level::Set_Remaining_Moves(int Rem) {
	this->Remaining_Moves = Rem;
}
void Level::Set_Time(double Time) {
	this->Time = Time;
}
void Level::Set_pos_ball_init_x(double x) {
	this->pos_ball_init_x = x;
}
void Level::Set_pos_ball_init_y(double y) {
	this->pos_ball_init_y = y;
}
void Level::Set_pos_hole_init_x(double x) {
	this->pos_hole_init_x = x;
}
void Level::Set_pos_hole_init_y(double y) {
	this->pos_hole_init_y = y;
}
SDL_Renderer* Level::Get_Main_Launcher_Render() {
	return this->l.Get_Render();
}
Launcher Level::Get_Launcher() {
	return this->l;
}
bool Level::Get_Run() {
	return this->run;
}
bool* Level::Get_pRun() {
	return this->prun;
}
void Level::Set_Run(bool b){
	this->run = b;
}
bool Level::Get_Stop() {
	return this->stop;
}
void Level::Set_Stop(bool s) {
	this->stop = s;
}