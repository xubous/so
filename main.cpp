#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cmath>

#define megabite 1024
#define space_storage_input 100
#define space_memory_input 8

// using namespace std;

/* ------------- Assistant ------------------- */
void pre_config ( ) { srand ( time ( 0 ) ); }

void clear_console ( )
{
    #ifdef _WIN32 
        system ( "cls" );
    #elif __linux__  
        system ( "clear" );
    #endif
}

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
    int max = 3072;

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

        long get_storage_application ( ) { return process -> get_space_storage_process ( ); }

        long get_memory_application ( ) { return process -> get_space_memory_process ( ); }

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
        long storage_used;

    public :
        Storage ( long capacity_storage_megabites )
        {
            this -> capacity_storage_megabites = capacity_storage_megabites;;
            storage_used = 0; 
        }

        ~ Storage ( ) { }

        long get_storage_megabites ( ) { return capacity_storage_megabites; }

        void change_storage_used ( long application_storage ) { storage_used = storage_used + application_storage; }

        long get_storage_used ( ) { return storage_used; }
};
/* -------------- End Storage ---------------- */


/* --------------- Memory ------------------- */
class Memory
{
    private :
        long capacity_memory_megabites;
        long memory_used;

    public :
        Memory ( long capacity_memory_megabites )
        {
            this -> capacity_memory_megabites = capacity_memory_megabites;
            memory_used = 0;
        }

        ~ Memory ( ) { }

        long get_memory_megabites ( ) { return capacity_memory_megabites; }

        void chance_memory_used ( long application_storage ) { memory_used = memory_used + application_storage; }

        long get_memory_used ( ) { return memory_used; }
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
class NodeIntArray
{
    public :
        int value;
        NodeIntArray * next;

        NodeIntArray ( )
        {
            value = 0;
            next = nullptr;
        }

        NodeIntArray ( int value )
        {
            this -> value = value;
            next = nullptr;
        }

        ~ NodeIntArray ( )
        {
            delete next;
        }
};

class IntArray
{
    public :
        NodeIntArray * head;
        NodeIntArray * last;

        IntArray ( )
        {
            head = new NodeIntArray ( );
            last = head;
        }

        ~ IntArray ( )
        {
            delete head;
            delete last;
        }

        bool is_empty ( )
        {
            return head -> next == nullptr;
        }

        void invert_integer_from_bin ( )
        {
            int assistant [ 100 ] = { 0 };
            int count = 0;

            while ( ! this -> is_empty ( ) )
            {
                assistant [ count ] = this -> pop ( );
                count = count + 1;
            }

            for ( int i = 0; i < count; i ++ ) 
            {
                this -> push ( assistant [ i ] );
            }
        }

        void int_to_bin ( int integer_from_bin )
        {
            int copy = integer_from_bin;

            while ( copy > 0 )
            {
                int rest = copy % 2;

                push ( rest );

                copy = copy / 2;
            }

            invert_integer_from_bin ( );
        }

        int length ( )
        {
            int count = 0;
            NodeIntArray * current = head -> next;

            while ( current != nullptr )
            {
                count ++;
                current = current -> next;
            }

            return count;
        }

        int bin_to_int ( )
        {
            int response = 0;
            int size = length ( ) - 1;
            NodeIntArray * current = head -> next;

            while ( current != nullptr )
            {
                response = response + current -> value * std::pow ( 2, size );
                size --;
                current = current -> next;
            }

            return response;
        }

        void push ( int x )
        {
            last -> next = new NodeIntArray ( x );
            last = last -> next;
        }

        int pop ( )
        {
            if ( head == last ) return - 1;

            if ( head -> next == last )
            {
                int value = last -> value;

                delete last;

                last = head;
                head -> next = nullptr;

                return value;
            }

            NodeIntArray * current = head -> next;

            while ( current -> next != last && current -> next != nullptr ) current = current -> next;

            int value = last -> value;

            last = current;
            last -> next = nullptr;

            return value;
        }

        void show ( )
        {
            NodeIntArray * current = head -> next;

            if ( is_empty ( ) ) std::cout << "Empty" << std::endl;

            while ( current != nullptr )
            {
                std::cout << current -> value << " ";

                current = current -> next;
            }

        }
};

class Ula
{
    public :
        Ula ( ) { }

        ~ Ula ( ) { }

        bool and_ ( int m1, int m2 ) { return m1 && m2; }

        bool or_ ( int m1, int m2 ) { return m1 || m2; }

        bool xor_ ( int m1, int m2 ) { return m1 ^ m2; }

        bool not_ ( bool m1 ) { return ! m1; }

        int sum ( int first_installment, int second_installment ) 
        {
            IntArray * sum_response = new IntArray ( );
            IntArray * first_installment_bin = new IntArray ( );
            IntArray * second_installment_bin = new IntArray ( );
            int carry = 0;

            first_installment_bin -> int_to_bin ( first_installment );
            second_installment_bin -> int_to_bin ( second_installment );

            while ( ! first_installment_bin -> is_empty ( ) || ! second_installment_bin -> is_empty ( ) )
            {
                int bit_01 = first_installment_bin -> is_empty ( ) ? 0 : first_installment_bin -> pop ( );
                int bit_02 = second_installment_bin -> is_empty ( ) ? 0 : second_installment_bin -> pop ( );
                int sum = bit_01 + bit_02 + carry;
                int result_bit = sum % 2;

                carry = sum / 2;

                sum_response -> push ( result_bit );
            }

            if ( carry ) sum_response -> push ( carry );

            sum_response -> invert_integer_from_bin ( );

            return sum_response -> bin_to_int ( );
        }

        int sub ( int minuend, int subtrahend )
        { 
            IntArray * sub_response = new IntArray ( );
            IntArray * minuend_bin = new IntArray ( );
            IntArray * subtrahend_bin = new IntArray ( );
            int borrow = 0;

            minuend_bin -> int_to_bin ( minuend );
            subtrahend_bin -> int_to_bin ( subtrahend );

            while ( ! minuend_bin -> is_empty ( ) || ! subtrahend_bin -> is_empty ( ) )
            {
                int bin_01 = minuend_bin -> is_empty ( ) ? 0 : minuend_bin -> pop ( );
                int bin_02 = subtrahend_bin -> is_empty ( ) ? 0 : subtrahend_bin -> pop ( );
                int diff = bin_01 - bin_02 - borrow;

                if ( diff < 0 )
                {
                    diff = diff + 2;
                    borrow = 1;
                } else
                    {
                        borrow = 0;
                    }
                
                    sub_response -> push ( diff );
            }

            while ( sub_response -> length ( ) > 1 )
            {
                int bit = sub_response -> pop ( );

                if ( bit == 1 )
                {
                    sub_response -> push ( bit );

                    break;
                }
            }

            return sub_response -> bin_to_int ( );
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

        Ula * get_ula ( )
        {
            return ula;
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
            clear_console ( );

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

            if ( ( storage -> get_storage_used ( ) + application -> get_storage_application ( ) ) <= storage -> get_storage_megabites ( ) && ( memory -> get_memory_used ( ) < application -> get_memory_application ( ) ) <= memory -> get_memory_megabites ( ) )
            {
                tree -> insert ( application );
                cpu -> insert_cpu ( application -> get_pid_app ( ) );
                storage -> change_storage_used ( application -> get_storage_application ( ) );
                memory -> chance_memory_used ( application -> get_memory_application ( ) );
            } else 
                {
                    std::cout << "Memory Overflow Or Full Space Error" << std::endl;
                }
        }

        void system_ ( )
        {
            std::cout << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "Hello, " << user -> get_username ( ) << " ! This Is A Virtual Operating System" << std::endl;
            std::cout << "Storage : " << storage -> get_storage_megabites ( ) << " mb !" << std::endl;
            std::cout << "Memory : " << memory -> get_memory_megabites ( ) << " mb !" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            tree -> show ( );
            std::cout << "\n" << "Pids List : " << std::endl;
            cpu -> cpu_ ( );
            std::cout << std::endl;
            std::cout << "Storage Used : " << storage -> get_storage_used ( ) << " mb !   Free : " << storage -> get_storage_megabites ( ) - storage -> get_storage_used ( ) << " mb ! " << std::endl;
            std::cout << "Memory Used  : " << memory -> get_memory_used ( ) << " mb !   Free : " << memory -> get_memory_megabites ( ) - memory -> get_memory_used ( ) << " mb ! " << std::endl;
            std::cout << std::endl;
        }

        Ula * get_ula ( )
        {
            return cpu -> get_ula ( );
        }

        int menu_calculator ( )
        {
            int option = - 1;

            std::cout << "---------------------------------------" << std::endl;
            std::cout << "Choose One Operation :" << std::endl;
            std::cout << "0 - Exit" << std::endl;
            std::cout << "1 - Sum" << std::endl;
            std::cout << "2 - Sub" << std::endl;
            std::cout << "3 - And " << std::endl;
            std::cout << "4 - Or" << std::endl;
            std::cout << "5 - Xor" << std::endl;
            std::cout << "6 - Not" << std::endl;
            std::cout << "---------------------------------------" << std::endl;

            std::cin >> option;

            switch ( option )
            {
                case 0: return 0;

                case 1: return 1;

                case 2: return 2;

                case 3: return 3;

                case 4: return 4;

                case 5: return 5;

                case 6: return 6;
                
                default:
                    break;
            }

            return option;
        }

        void menu ( )
        {
            int option = - 1;

            do
            {
                clear_console ( );

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
                        {
                            clear_console ( );
                            while ( getchar ( ) != '\n' ) getchar ( );
                            std::cout << "Enter to exit ..." << std::endl;
                            getchar ( );
                            std::cout << "Bye <3\t" ;
                            break;
                        }

                    case 1:
                        {
                            clear_console ( );
                            system_ ( ); 
                            while ( getchar ( ) != '\n' ) getchar ( );
                            std::cout << "Enter to continue ..." << std::endl;
                            getchar ( );
                            break;
                        }

                    case 2:
                        {
                            clear_console ( );
                            insert ( );
                            while ( getchar ( ) != '\n' ) getchar ( );
                            std::cout << "Enter to continue ..." << std::endl;
                            getchar ( );
                            break;
                        }

                    case 3:
                        {
                            clear_console ( );
                            user -> to_string ( );
                            while ( getchar ( ) != '\n' ) getchar ( );
                            std::cout << "Enter to continue ..." << std::endl;
                            getchar ( );
                            break;
                        }
                    
                    case 4:
                        {
                            clear_console ( );
                            int option_menu_calculator = - 1;
                            Ula * ula = cpu -> get_ula ( );

                            do
                            {
                                clear_console ( );

                                option_menu_calculator = menu_calculator ( );

                                int first_value = 0, second_value = 0;

                                clear_console ( );

                               if ( option_menu_calculator != 6 && option_menu_calculator != 0 )
                               {
                                    std::cout << "Write the first value : " << std::endl;
                                    std::cin >> first_value;
                                    std::cout << "Write the second value : " << std::endl;
                                    std::cin >> second_value;
                               }

                                clear_console ( );

                                int result = 0;

                                switch ( option_menu_calculator )
                                {
                                    case 1:
                                        {
                                            result = ula -> sum ( first_value, second_value );
                                            std::cout << "Sum = " << result << std::endl;
                                            std::cout << std::endl;
                                            break;
                                        }
                                    
                                    case 2:
                                        {
                                            result = ula -> sub ( first_value, second_value );
                                            std::cout << "Sub = " << result << std::endl;
                                            std::cout << std::endl;
                                            break;
                                        }
                                    
                                    case 3:
                                        {
                                            result = ula -> and_ ( first_value, second_value );
                                            std::cout << "Result = " << result << std::endl;
                                            std::cout << std::endl;
                                            break;
                                        }

                                    case 4:
                                        {
                                            result = ula -> or_ ( first_value, second_value );
                                            std::cout << "Result = " << result << std::endl;
                                            std::cout << std::endl;
                                            break;
                                        }
                                    
                                    case 5:
                                        {
                                            result = ula -> xor_ ( first_value, second_value );
                                            std::cout << "Result = " << result << std::endl;
                                            std::cout << std::endl;
                                            break;
                                        }

                                    case 6:
                                        {
                                            bool input = false;

                                            std::cout << "Write A Bin : " << std::endl;
                                            std::cin >> input;
                                            clear_console ( );
                                            result = ula -> not_ ( input );
                                            std::cout << "Result = " << result << std::endl;
                                            std::cout << std::endl;
                                            break;
                                        }

                                    default:
                                        break;
                                }

                                while ( getchar ( ) != '\n' ) getchar ( );
                                std::cout << "Enter to continue ..." << std::endl;
                                getchar ( );

                            } while ( option_menu_calculator != 0 );

                            break;
                        }

                    default: break;
                }
            } while ( option != 0 );
            
        }
};
/* ---------------- End So ------------------- */

void test ( )
{
    // IntArray * arr = new IntArray ( );

    // arr -> int_to_bin ( 10 );
    // arr -> show ( );
    // std::cout << arr -> length ( ) << std::endl;
    // int response = arr -> bin_to_int ( );
    // std::cout << response << std::endl;

    // std::cout << std::endl;

    // Ula * ula = new Ula ( );
    
    // std::cout << ula -> sum ( 3, 2 ) << std::endl;
}

int main ( )
{   
    So * so = new So ( space_storage_input, space_memory_input );

    so -> menu ( );

    // test ( );

    return 0;
}
