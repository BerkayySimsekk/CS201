# Bilkent University CS 201 Assignments

Repository includes my solutions for the course Fundamental Structures of Computer Science I assignments. The course introduces the fundamentals of the computer programming with C++ programming. The memory leaks are tested with Valgrind for the
assignments. The code in the assignments are tested by using an automated test suite that includes multiple test cases on a remote server provided by Bilkent University.

## Assignments

- `Project 1` : Space Mission Management System
    - `Aim` : To manage varios space missions and spacecrafts, each mission and spacecraft must have a unique name. Each mission can have multiple assigned spacecrafts but each spacecraft can only be assigned to one mission at a time. The management system should
            support adding and removing missions and spacecraft, as well as assigning spacecrafts to missions. 
    - `Public Member Functions` : Add a mission to the system, remove a mission from the system, add a spacecraft to the system, remove a spacecraft from the system, assign a spacecraft to a mission, drop a spacecraft from a mission
                                show the list of all missions, show the list of all spacecrafts, show detailed information about a specific mission, show detailed information about a specific spacecraft.
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using dynamically allocated arrays with pointers. 
- `Project 2` : Runtime Complexity of Search Algorithms
    - `Aim` : To evaluate the growth rates of different algorithms using different inputs.
    - `Content` : The cases where the key is close to the beginning, is around the middle, is close to the end or does not exist are simulated seperately for the linear search, recursive linear search, binary search, jump search and random search;
                the runtimes for all of the cases for each of these search algorithms are measured.
- `Project 3` : Bilkent Beats
    - `Aim` : To create music streaming service that consists of users, songs and playlists which are identified by unique IDs across the system. A linked list of users and a linked list of songs are stored. For each user, a linked list of playlists are stored. For
            each playlist, a linked list of song IDs are stored. The users, songs and playlist are stored in a sorted order while the songs in the playlist are unsorted. 
    - `Public Member Functions` : Add a new user, remove the existing user, display all of the users, add a song, remove a song, display all of the songs in the music library, add a playlist, remove a playlist, add a song to a playlist, remove a song from the playlist
                                display the songs in the playlist.
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using Linked List objects.
- `Project 4` : City of Contagion
    - `Aim` : To simulate the spread of a pandemic in a city, "0" means empty block, "1" means a block with healthy individuals, "2" means a block with infected individuals that can spread the infection to the adjacent healthy blocks which are represented with "1". The
            infection cannot spread diagonally and it cannot spread to empty blocks represented with "0".
    - `Public Member Functions` : Display the states of all cells in the city grid at a given time, display the minimum number of days required for the given block to be infected, simulate the spread of the pandemic across the entire city grid to output the minimum time
                                required for the infection to reach all the healthy blocks. 
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using Queue objects, the Queue class is implemented by using Linked List objects. The information that contains the city grid information is kept in multidimensional
                dynamic arrays.
