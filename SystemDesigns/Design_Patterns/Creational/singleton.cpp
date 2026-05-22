#include<iostream>
#include <mutex>

using namespace std;


class GameSettingsEagerIntialize{

    private:
    int volume = 10;
    static GameSettingsEagerIntialize* instance;

    GameSettingsEagerIntialize(){}

    GameSettingsEagerIntialize(int volume){

        this->volume = volume;
    }

    GameSettingsEagerIntialize (const GameSettingsEagerIntialize&) = delete;
    GameSettingsEagerIntialize& operator=(const GameSettingsEagerIntialize&) = delete;


    public:

        static GameSettingsEagerIntialize* getInstance(){
            return instance;
        }
    
};

class GameSettingsLazyIntialize{

    public:

        int volume = 10 ;

    private:

        static GameSettingsLazyIntialize* instance;
        static mutex mtx;

        GameSettingsLazyIntialize() {};
        GameSettingsLazyIntialize(int volume){
            this->volume = volume;
        }

        GameSettingsLazyIntialize(const GameSettingsLazyIntialize&) = delete;
        GameSettingsLazyIntialize& operator=(const GameSettingsLazyIntialize&) = delete;
    
    public:
        

        static GameSettingsLazyIntialize* getInstance(){

             if(instance == nullptr){

                lock_guard<mutex> lock(mtx);

                if(instance == nullptr){

                    instance = new GameSettingsLazyIntialize();
                }

            }
            return instance;
       }

       

};

GameSettingsLazyIntialize* GameSettingsLazyIntialize::instance = nullptr;
mutex GameSettingsLazyIntialize::mtx;

GameSettingsEagerIntialize* GameSettingsEagerIntialize::instance = new GameSettingsEagerIntialize();

int main(){

    GameSettingsLazyIntialize* g1 = GameSettingsLazyIntialize::getInstance();
    GameSettingsLazyIntialize* g2 = GameSettingsLazyIntialize::getInstance();

    cout<< boolalpha << (g1 == g2) << endl;
    // g2->volume = 50;

    cout<<g1->volume << endl; 
    cout<<g2->volume;


    GameSettingsEagerIntialize* eager1 = GameSettingsEagerIntialize::getInstance();
    GameSettingsEagerIntialize* eager2 = GameSettingsEagerIntialize::getInstance();

    cout<<endl;
    cout<< boolalpha << (eager1 == eager2) << endl;


    return 0;
}