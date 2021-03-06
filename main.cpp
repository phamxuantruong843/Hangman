#include <iostream>
#include <ctime>
#include <string>

#define max_guess_count 7

using namespace std ;

const string word[]= {"Naruto","Sasuke","RAsengan","BanKai","RiCkroll"};

string Tolower(const string& word){
    string out = string(word.length(),' ') ;
    for(int i=0 ; i< word.length() ;i++) out[i]=tolower(word[i]);
    return out ;
}
string chooseWord(){
    int choose = rand()%(sizeof(word)/sizeof(string));
    return Tolower(word[choose]);
}

void initGame(string& secretWord,string& guessWord,int& badGuessCount){
    secretWord = chooseWord() ;
    int n = secretWord.length()  ;
    guessWord = string(n,'-');
    badGuessCount = 0 ;
}
const string picture[] = {
    "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
  "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",
};



void renderGame(const string& secretWord, const string& guessWord, int badGuessCount){
    system("cls") ;
     if(secretWord==Tolower(word[0])) cout << "Hint: A character in Naruto series..." << endl;
     if(secretWord==Tolower(word[1])) cout << "Hint: A character in Naruto series..." << endl ;
     if(secretWord==Tolower(word[2])) cout << "Hint: A ninjustu in Naruto series..." << endl ;
     if(secretWord==Tolower(word[3])) cout << "Hint: An iconic phrase in Bleach series..." << endl ;
     if(secretWord==Tolower(word[4])) cout << "Hint: Best Trolling..." << endl ;
    cout /*<< secretWord << " " */<< guessWord << "\n" << "Hearts: " << string (7-badGuessCount,'*') << endl ;
    cout << picture[badGuessCount] << endl;
}

char getInput(){
    string input ;
    cin >> input ;
    string in = Tolower(input) ;
    return in[0] ;
}

bool gameOver(const string& secretWord, const string& guessWord, int badGuessCount){
    return (secretWord==guessWord)||(badGuessCount>=max_guess_count);
}

bool contain (const string& word, char c){
    return (word.find(c)!=string::npos);
}

void update(char input, const string& secretWord, string& guessWord){
    for (int i=0; i<secretWord.length() ; i++ ){
        if(input==secretWord[i]) guessWord[i]=input ;
    }
}
void updateGame(char input, const string& secretWord, string& guessWord, int& badGuessCount){
    if(contain(secretWord,input))
    update(input,secretWord,guessWord);
        else badGuessCount+=1 ;
}
void displayResults(const string& secretWord, const string& guessWord){
    if(secretWord==guessWord) cout << "Correct! You won!\n";
    else cout << "Incorrect! You lost!\n" << endl ;

}
bool newGame(){
    char ans ;
        cout << "New game? (y/n)" << endl ;
        cin >> ans ;
        if(ans=='y'||ans=='Y') return true;
        else return false; 
}
int main()
{
    srand(time(0));

  string secretWord ;
  string guessWord ;
  int badGuessCount;
    do{
  initGame(secretWord, guessWord, badGuessCount) ;

  do {
  renderGame(secretWord,guessWord,badGuessCount) ;
  char input = getInput() ;
  updateGame(input,secretWord,guessWord,badGuessCount) ;
  } while (!gameOver(secretWord,guessWord,badGuessCount));
  renderGame(secretWord,guessWord,badGuessCount);
  displayResults(secretWord,guessWord) ;
    }while (newGame()==true) ;
  return 0;
}
