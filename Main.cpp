#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

using namespace std;

const int   LARGEUR_ECRAN = 800;
const int   HAUTEUR_ECRAN = 450;
const int         vitesseRaquetteGauche = 4;
const int         vitesseRaquetteDroite = 8;
const int         scoreForWin = 2;
int         scoreJoueur = 0;
int         scoreIa = 0;
int         etatJeu = 0;
int         vitesseBalleX = 5;
int         vitesseBalleY = -5;
bool        resultatVisible = false;
Rectangle   balle{50, 100, 32, 32};
Rectangle   raquetteGauche{0, 100, 32, 128};
Rectangle   raquetteDroite{LARGEUR_ECRAN - raquetteDroite.width, 100, 32, 128};
string      texteResultat;
Sound       sonDefaite;
Sound       sonMur;
Sound       sonOut;
Sound       sonPing;
Sound       sonVictoire;


void    draw();
void    update();
void    load();
void    unload();
bool    collision(Rectangle B, Rectangle G);
void    rebondSurRaquette(bool cotejoueur);
void    relancerBalle();

int main ()
{
    load();
    while(!WindowShouldClose()){
        update();
        draw();
    }
    unload(); 
    return 0;
}


void    draw(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(balle.x, balle.y, balle.width, balle.height, WHITE);
    DrawRectangleRec(raquetteGauche, WHITE);
    DrawRectangleRec(raquetteDroite, WHITE);
    DrawText(to_string(scoreIa).c_str(), 500, 50, 20, LIGHTGRAY);
    DrawText(to_string(scoreJoueur).c_str(), 300, 50, 20, LIGHTGRAY);
    if (resultatVisible)
        DrawText(texteResultat.c_str(), 350, 200, 20, LIGHTGRAY);
    EndDrawing();
}

void    update()
{
    if (etatJeu == 0)
    {
        balle.x += vitesseBalleX;
        balle.y -= vitesseBalleY;
        
        //La balle sort
        if (balle.y < 0)
        {
            vitesseBalleY = -vitesseBalleY;
            balle.y = 0;
        }
        if (balle.x < 0)
        {
            ++scoreIa;
            vitesseBalleX = -vitesseBalleX;
            relancerBalle();
            if (scoreIa >= scoreForWin)
            {
                etatJeu = 2;
                texteResultat = "Defaite";
                resultatVisible = "true";
                PlaySound(sonDefaite);
            }
            else
                PlaySound(sonOut);
        }
        if (balle.y > HAUTEUR_ECRAN - balle.height)
        {
            vitesseBalleY = -vitesseBalleY;
            balle.y = HAUTEUR_ECRAN - balle.height;
        }
        if (balle.x > LARGEUR_ECRAN - balle.width)
        {
            ++scoreJoueur;
            vitesseBalleX = -vitesseBalleX;
            relancerBalle();
            if (scoreJoueur >= scoreForWin)
            {
                etatJeu = 1;
                texteResultat = "Victoire";
                resultatVisible = "true";
                PlaySound(sonVictoire);
            }
            else
                PlaySound(sonOut);
        }
        // controler la raquette gauche
        if (IsKeyDown(KEY_S))
        {
            raquetteGauche.y += vitesseRaquetteGauche;
        }
        else if(IsKeyDown(KEY_W))
        {
            raquetteGauche.y -= vitesseRaquetteGauche;
        }
        
        //Empecher la balle de traverser les raquettes
        if (raquetteGauche.y < 0)
            raquetteGauche.y = 0;
        if (raquetteGauche.y > HAUTEUR_ECRAN - raquetteGauche.height)
            raquetteGauche.y = HAUTEUR_ECRAN - raquetteGauche.height;
        
        if (raquetteDroite.y < 0)
            raquetteDroite.y = 0;
        if (raquetteDroite.y > HAUTEUR_ECRAN - raquetteDroite.height)
            raquetteDroite.y = HAUTEUR_ECRAN - raquetteDroite.height;
        
        //Collision
        if(collision (balle, raquetteGauche))
        {
            rebondSurRaquette(true);
            PlaySound(sonMur);
        }
        else if(collision (balle, raquetteDroite))
        {
            rebondSurRaquette(false);
            PlaySound(sonMur);
        }
        
        //IA
        if (balle.y < raquetteDroite.y + raquetteDroite.height / 4)
            raquetteDroite.y -= vitesseRaquetteDroite;
        else if(balle.y > raquetteDroite.y + raquetteDroite.height * 3 / 4)
            raquetteDroite.y += vitesseRaquetteDroite;
    }
    else
    {
        if (IsKeyPressed(KEY_R))
        {
            scoreJoueur = 0;
            scoreIa = 0;
            texteResultat = "";
            etatJeu = 0;
        }
    }
}

void    load(){
    InitWindow(800, 450, "Interaction");
    SetTargetFPS(90);
    InitAudioDevice();
    
    sonDefaite = LoadSound("son/defaite.wav");
    sonMur = LoadSound("son/mur.wav");
    sonOut = LoadSound("son/out.wav");
    sonPing = LoadSound("son/ping.wav");
    sonVictoire = LoadSound("son/victoire.wav");
}

void unload(){
    CloseWindow();
}

bool collision(Rectangle B, Rectangle G)
{
    int         xMinB = B.x;
    int         yMinB = B.y;
    int         xMaxB = B.x + B.width;
    int         yMaxB = B.y + B.height;
    int         xMinG = G.x;
    int         yMinG = G.y;
    int         xMaxG = G.x + G.width;
    int         yMaxG = G.y + G.height;
    
    //Test de collision
    if (!(xMinB > xMaxG || yMinB > yMaxG || xMaxB < xMinG || yMaxB < yMinG))
        return true;
    else
        return false;
}

void    rebondSurRaquette(bool cotejoueur)
{
    vitesseBalleX = -vitesseBalleX;
    if (cotejoueur)
        balle.x = raquetteGauche.x + balle.width;
    else
        balle.x = raquetteDroite.x - balle.width;
}

void    relancerBalle()
{
    balle.x = 50;
    balle.y = 100;
}