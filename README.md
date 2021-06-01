# Movie Recommender
 
 Authors: [Alice Thai](https://github.com/athai026),
          [Arman Essaian](https://github.com/AEssaian740),
          [Daimon Spilker](https://github.com/daimonspilker),
          [Ngoc Nguyen](https://github.com/nnguyen702)
         
 

> ## Project Description
An important aspect of this project system is the ability to use the data provided by user's opinions to influence the decision making of other users when choosing between a variety of products. Moreover, a movie recommender is a helpful application which can also help viewers easily find what fits their needs based on different interests.

> ## Languages/Tools/Technologies used
  * C++ language - Used for all coding 
  * Movie databases - For the program to read from so it can recommend something (will include things such as title, genre, director, etc.)
  * Valgrind - To check for memory leaks
  * Googletest - To create and run unit tests
  * Visual Studio's Local Windows Debugger - User for debugging our code
  
> ## Input/Output 
* Developer Input: (from movie databases) Things such as movie titles, genres, directors, actors, year of release, aggregate ratings, etc. 
* User Input: Will include things like favorite genres or movies or directors. They will be used as user specified tags so that the program can make accurate recommendations.
* Output: A list of movie recommendations that will include the title, genre(s), director(s), actor(s), rating, and release year.

> ## Design Patterns
  * Composite Pattern: allows us to arrange objects into tree structures to represent partially entirely hierarchical structures. We'll use this pattern to create our Search and Sort class. For example, we have a variety of ways to search for a movie, by genre or by actors, so we'll create an algorithm that allows users to enter their keywords. Also, if they want to search for a movie using multiple keywords, we can create another algorithm that allows the user to enter two keywords. Thus, we will create an interface Search class which have the common functions. This way we can easily add the new subclasses that use those common functions but implement a specific algorithm according to the user's request.
  * Strategy Pattern: Our movie database is organized into many categories and subcategories, and there are different methods that could be used to search and sort the movie data. Therefore, we will create three classes, Moviedatabase, Search, and Sort, and keep Search and Sort self-contained and independent of the document structures (Moviedatabase). This way we can easily add or remove new algorithms for search and sort function but not affect the document structures. Also, if we want to add a new class for Moviedatabase, it would not affect the function of Search and Sort.

> ## Class Diagram
  ![cs100_projectOMT_movie](https://user-images.githubusercontent.com/81598691/120172680-2727e000-c1b8-11eb-8e14-3173c17d023d.png)

 > ## Class description:
   * MovieDatabase: This class allows us to create a movie database with many different functions, like adding new rows of movie data to our vector of movie data. The print_recommendation() function in this class will also allow us to print out the list of recommended movies. Set_search is to set keywords we want to search for movies.
   * Search class: This is an interface class that includes a common function used in its subclasses. Search_Column, Search_Contains, Search_And, and Search_Or are derived classes from Search. The user will be prompted to type certain keywords that describes what they are searching for. Search_Contains sets the movie to contain certain keywords. Search_And search for movies contain two certain keywords. Search_Or returns the union of the two keywords/categories the user inputs.
   * Sort class: This is a class that contains one function to sort the list of recommended movies by the rating or the release year. It takes in two parameters, the Moviedatabase object which contains the list of recommended movies and the column by which the movies are to be sorted. 
     - The relationship between the Moviedatabase with the Search class is representative of the strategy pattern. The relationship between the Search class and its subclasses is representative of the composite pattern.
 
 > ## Week 8 Scrum Meet
   For this meeting we.... 
   * finalized our OMT diagram and overall project structure
     - We originally wanted to implement both our Search and Sort function as a strategy pattern but soon figured that the Sort class only needed to be its own class with one function.
   * planned out the rest of our tasks
     - At the time of this meeting, the main Search and Sort classes were still being developed. The Moviedatabase class was nearly complete as well. There were a few ideas we wanted to develop such as the user's favorite list, a main menu implementation, and a Search_Not function implementation. 
     <!--- Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint --->
     <!--- Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority? --->
     <!--- What tasks you are planning for this next sprint. --->
 
 > ## Contributions
   * Alice: I was responsible for the implementation of the Sort function and the user's favorite movies list feature. Originally, we wanted to implement Sort as a strategy pattern with sorting by rating and sorting by year as two separate algorithms. We eventually realized that they were essentially the same function with only the column number changed, so I condensed the function down to one class. I also had to export all the code onto Visual Studios in order to use its Local Windows Debugger since I was encountering segmenation faults in many places. Next, I implemented the user's favorite movies list. This feature allows the user to compile a list of their favorite movies and get recommendations based on the most abundant genre in their list. This feature also saves the user's favorite movies onto a text file so that the next time they use the program, their list is not lost. 
   * Arman: 
   * Daimon: I was responsible for the menu and originally had wrote the code for it inside of the main function in main.cpp but decided to create a seperate function to clean things up and make it more readable. I ended up swithced the layout of the code for the menu to use switch cases inside of a while loop to ensure a smooth functioning interface for the client. Originally i wrote the code with a bunch of if else statements, but that turned out to be harder to keep track of for me and was a little more messy with how I set it up. I did mostly all of the code in CLion on my laptop and then transferred the code to Linux terminal to make sure things were still wokring there as well and could be tested in valgrind. I also made changes to improve readability for an better UX, and edited the search function to allow for a less confusion during the selection process in the menus.
   * Ngoc: 

 > ## Screenshots
   <img width="607" alt="quit" src="https://user-images.githubusercontent.com/72218234/120270064-ce128780-c25d-11eb-928b-c84ec6f90d8f.png">
   <img width="705" alt="search1" src="https://user-images.githubusercontent.com/72218234/120270101-dc60a380-c25d-11eb-96d0-d7dc72c6e445.png">
   <img width="705" alt="search2" src="https://user-images.githubusercontent.com/72218234/120270106-dec2fd80-c25d-11eb-9021-4087d3013a89.png">
   <img width="705" alt="fav1" src="https://user-images.githubusercontent.com/72218234/120270126-e682a200-c25d-11eb-98eb-137b80c1193d.png">
   <img width="705" alt="fav2" src="https://user-images.githubusercontent.com/72218234/120270138-ed111980-c25d-11eb-84ca-1abe598edd80.png">
   <img width="705" alt="fav3" src="https://user-images.githubusercontent.com/72218234/120270144-f00c0a00-c25d-11eb-8613-3a3bdb10773a.png">
   <img width="705" alt="fav4" src="https://user-images.githubusercontent.com/72218234/120270153-f26e6400-c25d-11eb-9c94-118a5e503be3.png">
 
 ## Installation/Usage
 > Instructions on installing and running your application

 > ## Testing
   To test our code, we used googletest to create and run unit tests for our Search class, Sort function, and the function within the UserFavList class that finds the most abundant genre in the user's list of favorite movies. When implementing the Sort and Search functions together, many errors and segmentation faults were encountered. Valgrind was used to try to locate what was causing these segmentation faults, but the information given was not particularly helpful. So, the code was exported onto Visual Studios in order to use its Local Windows Debugger. After all errors and segmetnations faults were cleared, valgrind was used again to check for any memory leaks. Fortunately, none were present.
   ![cs100_project_valgrindreport](https://user-images.githubusercontent.com/81598691/120268370-88a08b00-c25a-11eb-8069-b440005f8a6c.PNG)
