
# Movie Recommender
 
 Authors: [Daimon Spilker](https://github.com/daimonspilker)
          [Ngoc Nguyen](https://github.com/nnguyen702)
          [Saul Mendoza](https://github.com/smendoza07)
 

## Project Description
* One of the important aspects of this project system is the ability to use the data provided by user's opinions to influence the decision making of other users when choosing between a variety of products. Moreover, a movie recommender is a helpfull application which can also help viewers easily find what fits their needs based on different interests.

> ## Languages/Tools/Technologies used
  * C++ language - Used for all coding 
  * Movie databases - For the program to read from so it can recommend something (will include things such as title, genre, director, etc.)
  * Valgrind - to check for memory leaks
  
> ## Input/Output 
* Developer Input: (from movie databases) Things such as movie titles, genres, directors, actors, year of release, aggregate ratings, runtime, age rating, language, etc. 
* User Input: Will include things like favorite genres or movies or directors. They will be  used as user specified tags so that the program can make accurate recommendations.
* Output: A movie recommendation that will include title and any relevant tags for the movie, as well as similar movies to choose from.

> ## Design Patterns
  * Composite Pattern: allows us to arrange objects into tree structures to represent partially entirely hierarchical structures. We'll use this pattern to create our Search and Sort class. For example, we have a variety of ways to search for a movie, by genre or starring, so we'll create an algorithm that allows users to enter their keywords. Also, if they want to search for a movie using multiple keywords, we can create another algorithm that allows the user to enter two keywords.Thus, we will create an interface Search class which have the common functions, then we can easy add the new subclasses that use those common functions but implement a specific algorithm according to the user's request
  * Strategy Pattern: Our movie database is organized into many categories and subcategories, therefore, there are different ways of methods that could be used to search and sort the movie data. Therefore, we will create three classes MovieData, Search and Sort class,and  keep the Search and Sort in a self contained and independent of the document structures (MovieData). Indeed, we can easily add or remove new algorithms for search and sort function but not affect the document structures. Also, if we want to add a new class for MovieData, it would not affect the function of Search and Function.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
