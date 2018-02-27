

#include <string>

#include "Json.h"
#include "Bloc.h"

using json = nlohmann::json;

class FileInterface {
private:
	std::string fichier;
	void write(std::string str);

	json toJson(TXI txi);
	json toJson(UTXO utxo);
	json toJson(TX tx);
	json toJson(TXM txm);
	json toJson(Bloc bloc);
	json toJson(std::vector<Bloc> blocs);

	std::vector<Bloc> parse(std::string blocsJson);
	Bloc parseBloc(json j);
	TXM parseTxm(json j);
	TX parseTx(json j);
	UTXO parseUtxo(json j);
	TXI parseTxi(json j);

public:
	// Constructeur : initialisation la classe et lit le fichier json passé en paramètre
	FileInterface(std::string fichier);

	// Insert le bloc à la suite du fichier - génére une exception si le hash du bloc précédent n'est pas bon
	void insert(Bloc bloc);

	// Recherche un bloc en fonction de son hash - génére une exception si aucun bloc n'est trouvé
	Bloc findByHash(std::string hash);

	// Recherche un bloc en fonction de sa position dans la chaine - génére une exception si aucun bloc n'est trouvé
	Bloc findByIndex(std::string hash);

	// Parcourt tous les blocs afin de savoir s'ils sont conformes - génére une exception si un n'est pas conforme
	void verification();

	// Retourne tous les blocs constituant la blockchain sous forme de vecteur
	std::vector<Bloc> readAll();

	// Retourne un bloc sous forme de chaine de caractère. Si hash == true, renvoie la chaine de caracère avec le hash et le nonce, sinon sans le hash et le nonce
	 std::string toString (bool hash);

};