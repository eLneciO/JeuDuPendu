#ifndef PENDU_H_INCLUDED
#define PENDU_H_INCLUDED

#include <string>
#include <set>
#include "../O_SDO/sujetDObservation.h"

/*!
 * \mainpage Jeu du %Pendu
 *
 * Documentation d'un ensemble de classes
 * m�tier pour jouer au jeu du pendu. Le mod�le de
 * conception <i>%Observateur / Sujet d'Observation</i>
 * est utilis�.
 *
 * Pour commencer, la description de la classe Pendu
 * est un bon point d'entr�e.
 */

/*!
 * 	\brief Classe pour jouer au pendu
 *
 * Cette classe permet de jouer au pendu.
 *
 * \author 	SMB & NVS.
 * \date 	F�vrier 2009, f�vrier 2011.
 */
class Pendu: public SujetDObservation
{
public:
	/*!
	 * Constructeur du jeu.
	 *
	 * \param fichier le nom complet du fichier o� puiser le mot,
	 * 			� savoir qu'une ligne du fichier est consid�r�e comme un mot
	 * 			et que le fichier doit se terminer par une ligne vide.
	 * \param nbrVie le nombre de propositions de lettres non pr�sentes
	 * 					dans le mot autoris�es. Valeur par d�faut : 6.
	 *
	 * \exception std::string si le fichier est introuvable ou si on tente
	 * 							de cr�er une partie avec z�ro (0)
	 * 							point de vie.
	 */
	Pendu(const char * fichier, unsigned nbrVie = 6) throw (std::string);

	/*!
	 * Permet de savoir si la partie est finie ou non, ind�pendamment
	 * de la victoire ou de la d�faite du joueur.
	 *
	 * \return true si la partie est finie.
	 */
	bool fini() const;

	/*!
	 * G�re enti�rement une proposition de lettre faite par le joueur.
	 *
	 * \param lettre la lettre propos�e, en minuscule ou majuscule
	 * 					<i>sans</i> accent.
	 *
	 * \exception std::string si la partie est finie ou que le param�tre
	 * 							n'est pas une lettre, ind�pendamment de la
	 * 							casse.
	 */
	void proposition(char lettre) throw (std::string);

	/*!
	 * Permet de conna�tre le mot � trouver, une fois la partie finie.
	 *
	 * \exception std::string si on appelle cette m�thode alors que
	 * 							la partie est toujours en cours.
	 */
	std::string solution() const throw (std::string);

	/*!
	 * Permet de conna�tre l'�tat d'avancement de la recherche.
	 *
	 * \return le mot trouv� par le joueur o� les lettres non trouv�es
	 * 			sont remplac�es par un point d'interrogation ('?').
	 */
	std::string motEnCours() const;

	/*!
	 * Permet de savoir combien de propositions erron�es sont
	 * encore autoris�es.
	 *
	 * \return l'esp�rance de vie sachant que z�ro (0) indique la fin
	 * 			de la partie en cas de d�faite.
	 */
	unsigned vie() const;

	/*!
	 * Permet de savoir si le joueur a gagn� la partie.
	 *
	 * \return true si le joueur a gagn�.
	 */
	bool gagne() const;

	/*!
	 * Permet de conna�tre la taille (le nombre de lettres) du mot
	 * � trouver.
	 *
	 * \return le nombre de lettres du mot � trouver.
	 */
	unsigned taille() const;

	/*!
	 * Permet de conna�tre les lettres d�j� propos�es.
	 *
	 * \return l'ensemble des lettres propos�es.
	 */
	std::set<char> lettreProposee() const;

	/*!
	 * Permet de conna�tre les lettres qui n'ont
	 * pas encore �t� propos�es.
	 *
	 * \return l'ensemble des lettres restantes.
	 */
	std::set<char> lettreRestante() const;

private:
	std::string motATrouver;
	std::string leMotEnCours;
	unsigned nbrVie;
	unsigned nbrLettre;
	bool enCours;
	bool aGagne;

	std::set<char> _lettreProposee;
	std::set<char> _lettreRestante;
};

#endif // PENDU_H_INCLUDED
