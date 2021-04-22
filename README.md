
# Movie Recommender
 
 > Authors: [Daimon Spilker] ()
 >          [Ngoc Nguyen] (https://github.com/nnguyen702)
 >          [Saul Mendoza] (https://github.com/smendoza07)
 

## Project Description
 > * One of the important aspects of this project system is the ability to use the data provided by user's opinions to influence the decision making of other users when choosing between a variety of products. Moreover, a movie recommender is a helpfull application which can also help viewers easily find what fits their needs based on different interests.
 > 
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++ language, movie database. [toolname](link) - Short description
 >   
 > * Developer Input: Movie titles, genre, director, actors, year of release, aggregate ratings, runtime, age rating,language. 
 > * User Input: Genre, user specified tags.
 > * Output: Movie title and relevant tags, similar movie titles.
 > 
 > * What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:
 >   * Composite Pattern: The composite pattern allow us to compose objects into tree structures to represent part-whole hierarchies. The composite pattern allows us to create an object structure with the different movie genres as top level structures and further tags pertaining to the movie as leafs. This way, movies can be organized and seperated by the relevant information that the user has inputted.
 >   * Iterator Pattern:	Our movie database is organized into a tree collection with many categories and subcategories, therefore, one advantage of using iterators is that they offer common interfaces for any container type, allowing us an easy method to traverse through and check each element of the collection. We can also use the search and sort function of the iterator pattern in order to seek and output the movies in a certain order, such as rating or year of release.

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
 
