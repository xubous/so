#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

#define megabite 1024
#define space_storage_input 100
#define space_memory_input 8

// using namespace std;

/* ------------- Assistant ------------------- */
void pre_config ( ) { srand ( time ( 0 ) ); }

int random_number_pid ( )
{
    int min = 1000;
    int max = 10000;

    return min + rand ( ) % ( max - min ) + 1;
}

long random_number_storage ( ) 
{ 
    int min = 5000;
    int max = 70000;

    return min + rand ( ) % ( max - min + 1 ); 
}

long random_number_memory ( )
{
    int min = 0;
    int max = 16384;

    return min + rand ( ) % ( max - min + 1 ); 
}
/* ------------ End Assistant ---------------- */


/* ------------- Application ----------------- */
class Process
{
    private :
        int pid;
        long space_storage_process;
        long space_memory_process;

    public :
        Process ( ) 
        {
            pid = random_number_pid ( );
            space_storage_process = random_number_storage ( );
            space_memory_process = random_number_memory ( );
        }

        ~ Process ( ) { }

        int get_pid ( ) { return pid; }

        long get_space_storage_process ( ) { return space_storage_process; }

        long get_space_memory_process ( ) { return space_memory_process; }
};

class Application
{
    private :
        std::string name;
        Process * process;

    public :
        Application ( )
        {
            std::cout << "Write The Name Application : " << std::endl;
            std::cin >> name;

            process = new Process ( );
        }

        ~ Application ( )
        {
            delete process;
        }

        int get_pid_app ( ) { return process -> get_pid ( ); }

        void app_ ( )
        {
            std::cout << "Applicaction Runned : " << name << std::endl;
            std::cout << "Pid -> " << get_pid_app ( ) << std::endl;
            std::cout << "Storage Application -> " << process -> get_space_storage_process ( ) << std::endl;
            std::cout << "Memomy Application -> " << process -> get_space_memory_process ( ) << std::endl;
        }
};
/* ------------- End Application ------------- */


/* --------------- Storage ------------------- */
class Storage
{
    private :
        long capacity_storage_megabites;

    public :
        Storage ( long capacity_storage_megabites )
        {
            this -> capacity_storage_megabites = capacity_storage_megabites;;
        }

        ~ Storage ( ) { }

        long get_csm ( )
        {
            return capacity_storage_megabites;
        }
};
/* -------------- End Storage ---------------- */


/* --------------- Memory ------------------- */
class Memory
{
    private :
        long capacity_memory_megabites;

    public :
        Memory ( long capacity_memory_megabites )
        {
            this -> capacity_memory_megabites = capacity_memory_megabites;
        }

        ~ Memory ( ) { }

        long get_cmm ( )
        {
            return capacity_memory_megabites;
        }
};
/* -------------- End Memory ---------------- */


/* ------------------ Cpu -------------------- */

// ------------------------------------------- 
class NodeLinkedListPids
{
    private :
        int pid;
        NodeLinkedListPids * next;
        NodeLinkedListPids * previous;
    
    public :
        NodeLinkedListPids ( )
        {
            pid = 0;
            next = previous = nullptr;
        }

        NodeLinkedListPids ( int pid )
        {
            this -> pid = pid;
            next = previous = nullptr;
        }

        ~ NodeLinkedListPids ( ) 
        { 
            delete next;
            delete previous; 
        }

        int get_pid ( ) { return pid; }

        NodeLinkedListPids * get_next ( ) { return next; }

        NodeLinkedListPids * get_previous ( ) { return previous; }

        void set_next ( NodeLinkedListPids * next ) { this -> next = next; }

        void set_previous ( NodeLinkedListPids * previous ) { this -> previous = previous; }
};

class LinkedListPid
{
    private :
        NodeLinkedListPids * head;
        NodeLinkedListPids * last;

    public :
        LinkedListPid ( )
        {
            head = new NodeLinkedListPids ( );
            last = head;
        }

        ~ LinkedListPid ( ) 
        { 
            delete head; 
            delete last; 
        }

        void insert_linked_list ( int pid )
        {
            NodeLinkedListPids * node = new NodeLinkedListPids ( pid );

            last -> set_next ( node );
            last = last -> get_next ( );
        }

        void show ( )
        {
            if ( head == last ) std::cout << "Without Apps";

            NodeLinkedListPids * current = head -> get_next ( );

            while ( current != nullptr ) { std::cout << current -> get_pid ( ) << " "; current = current -> get_next ( ); }

            std::cout << std::endl;
        }
};
// -------------------------------------------

// -------------------------------------------
class Ula
{
    public :
        Ula ( ) { }

        ~ Ula ( ) { }

        bool and_ ( bool m1, bool m2 ) { return m1 && m2; }

        bool or_ ( bool m1, bool m2 ) { return m1 || m2; }

        bool xor_ ( bool m1, bool m2 ) { return m1 ^ m2; }

        bool not_ ( bool m1 ) { return ! m1; }

        int sum ( std::string first_installment, std::string second_installment ) 
        {
            return 0;
        }

        int sub ( std::string minuend, std::string subtrahend )
        { 
            return 0;
        }

        int increment ( std::string input ) 
        { 
            return 0;
        }

        int decrement ( std::string input ) 
        { 
            return 0;
        }
};
// -------------------------------------------                                                                                   

// -------------------------------------------
class Mmu
{
    public :
        Mmu ( ) { }

        ~ Mmu ( ) { }

        void alloc_ ( ) { }

        void free_ ( ) { }

        void protect_ ( ) { }
        
        void swap_ ( ) { }
};
// -------------------------------------------

// -------------------------------------------
class Mux
{
    public :
        Mux ( ) { }

        ~ Mux ( ) { }
};

class Demux
{
    public :
        Demux ( ) { }

        ~ Demux ( ) { }
};

class Control
{
    private :
        Mux * mux;
        Demux * demux;

    public :
        Control ( )
        {
            mux = new Mux ( );
            demux = new Demux ( );
        }

        ~ Control ( )
        {
            delete mux;
            delete demux;
        }
};
// -------------------------------------------

// -------------------------------------------
class Cpu
{
    private :
        LinkedListPid * ll;
        Mmu * mmu;
        Ula * ula;
        Control * control;

    public :
        Cpu ( ) 
        {
            ll = new LinkedListPid ( );
            ula = new Ula ( );
            mmu = new Mmu ( );
            control = new Control ( );
        }

        ~ Cpu ( )
        {
            delete ll;
            delete ula;
            delete mmu;
            delete control;
        }

        void insert_cpu ( int pid )
        {
            ll -> insert_linked_list ( pid );
        }

        void cpu_ ( )
        {
            ll -> show ( );
        }
};

/* ---------------- End Cpu ------------------ */


/* --------------- System ------------------- */
class NodeSystemApplication
{
    private :
        Application * application;
        NodeSystemApplication * left;
        NodeSystemApplication * right;
    
    public :
        NodeSystemApplication ( Application * application )
        {
            this -> application = application;
            left = right = nullptr;
        }

        ~ NodeSystemApplication ( )
        {
            delete application;
            delete left;
            delete right;
        }

        int get_pid_node ( ) { return application -> get_pid_app ( ); }

        NodeSystemApplication * get_left ( ) { return left; }

        NodeSystemApplication * get_right ( ) { return right; }

        void set_left ( NodeSystemApplication * left ) { this -> left = left; }
        
        void set_right ( NodeSystemApplication * right ) { this -> right = right; }

        void show ( ) { application -> app_ ( ); }
};

class Tree
{
    private :
        NodeSystemApplication * root;

    public :
        Tree ( )
        {
            root = nullptr;
        }

        ~ Tree ( )
        {
            delete root;
        }

        NodeSystemApplication * insert_rec ( Application * application, NodeSystemApplication * i )
        {
            if ( i == nullptr ) { return new NodeSystemApplication ( application ); }
            else if ( application -> get_pid_app ( ) > i -> get_pid_node ( ) ) { i -> set_right ( insert_rec ( application, i -> get_right ( ) ) ); }
            else if ( application -> get_pid_app ( ) < i -> get_pid_node ( ) ) { i -> set_left ( insert_rec ( application, i -> get_left ( ) ) ); }

            return i;
        }

        NodeSystemApplication * insert ( Application * application )
        {
            root = insert_rec ( application, root );

            return root;
        }

        void show_tree ( NodeSystemApplication * i )
        {
            if ( i != nullptr )
            {
                show_tree ( i -> get_left ( ) );
                std::cout << std::endl;
                i -> show ( );
                show_tree ( i -> get_right ( ) );
            }
        }

        void show ( )
        {
            show_tree ( root );
        }
};
/* ------------- End System ----------------- */


/* ---------------- User --------------------- */
class User
{
    private :
        std::string username;
        std::string password;

    public :
        User ( )
        {
            system ( "clear" );

            std::cout << "Write A Username : " << std::endl;
            std::cin >> username;

            std::cout << "Write A Password : " << std::endl;
            std::cin >> password;
        }

        std::string get_username ( )
        {
            return username;
        }

        std::string get_password ( )
        {
            return password;
        }

        void to_string ( )
        {
            std::cout << "Username : " << username << std::endl;
            std::cout << "Password : " << password << std::endl;
            std::cout << std::endl;
        }
};
/* -------------- End User ------------------- */


/* ------------------ So --------------------- */
class So
{
    private :
        Storage * storage;
        Memory * memory;
        Cpu * cpu;
        Tree * tree;
        User * user;

    public :
        So ( int space_capacity, int memory_capacity )
        {
            pre_config ( );

            long capacity_storage_megabites = space_capacity * megabite;
            long capacity_memory_megabites = memory_capacity * megabite;

            storage = new Storage ( capacity_storage_megabites );
            memory = new Memory ( capacity_memory_megabites );
            cpu = new Cpu ( );
            tree = new Tree ( );
            user = new User ( );
        }

        ~ So ( )
        {
            delete storage;
            delete memory;
            delete cpu;
            delete tree;
            delete user;
        }

        void insert ( )
        {
            Application * application = new Application ( );

            tree -> insert ( application );
            cpu -> insert_cpu ( application -> get_pid_app ( ) );
        }

        void system_ ( )
        {
            std::cout << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "| Hello This Is A Virtual Operating System              |" << std::endl;
            std::cout << "| Storage : " << storage -> get_csm ( ) << " mb !                                 |" << std::endl;
            std::cout << "| Memory : " << memory -> get_cmm ( ) << " mb !                                    |" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            tree -> show ( );
            std::cout << "\n" << "Pids List : " << std::endl;
            cpu -> cpu_ ( );
            std::cout << std::endl;
        }

        void menu ( )
        {
            int option = - 1;

            do
            {
                system ( "clear" );

                std::cout << "---------------------------------------" << std::endl;
                std::cout << "| 1 - show system                     |" << std::endl;
                std::cout << "| 2 - insert program                  |" << std::endl;
                std::cout << "| 3 - user info                       |" << std::endl;
                std::cout << "| 4 - calculator                      |" << std::endl;               
                std::cout << "| 0 - Exit system                     |" << std::endl;
                std::cout << "---------------------------------------" << std::endl;
                std::cout << "Choose Option : " << std::endl;

                std::cin >> option;

                switch ( option )
                {
                    case 0:
                        system ( "clear" );
                        while ( getchar ( ) != '\n' ) getchar ( );
                        std::cout << "Enter to exit ..." << std::endl;
                        getchar ( );
                        std::cout << "Bye <3\t" ;
                        break;

                    case 1:
                        system ( "clear" );
                        system_ ( ); 
                        while ( getchar ( ) != '\n' ) getchar ( );
                        std::cout << "Enter to continue ..." << std::endl;
                        getchar ( );
                        break;

                    case 2:
                        system ( "clear" );
                        insert ( );
                        while ( getchar ( ) != '\n' ) getchar ( );
                        std::cout << "Enter to continue ..." << std::endl;
                        getchar ( );
                        break;

                    case 3:
                        system ( "clear" );
                        user -> to_string ( );
                        while ( getchar ( ) != '\n' ) getchar ( );
                        std::cout << "Enter to continue ..." << std::endl;
                        getchar ( );
                        break;

                    default:
                        break;
                }
            } while ( option != 0 );
            
        }
};
/* ---------------- End So ------------------- */


int main ( )
{   
    So * so = new So ( space_storage_input, space_memory_input );

    so -> menu ( );

    return 0;
}
