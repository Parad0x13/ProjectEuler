On 20Oct13 I decided for certain that I want to solve all of Project Euler's equations. Currently as of today there are 441 total questions. I have a long ways to go since I've only answered 44 questions.

I wonder how long it will take me to answer all questions, I know I'll have to achieve a certain level of mathematical competence probably through school (which I really need to make sure I start up soon). Any further updates on my feelings on my progress will be annotated here

On 2019.05.30.1939.EST I've decided to re-manage the way this entire repo is structured and fix some old issues
At this point not everything is properly renamed nor is the hierarchy of folders exactly how I want it
I've attempted to future-proof the puzzle naming conventions by using 4 digits. I hope they do 5 digit or more equations but I doubt it

Of note both puzzles 18 and 67 used the same source originally so that code is duplicated to keep the naming and hierarchy conventions

On 2019.10.16.2045.EST I've decided to re-manage it a whole new way again
Had to decide on a trade-off regarding Jupyter Notebooks here
On the one hand they are nice and easy to use
On the other hand it means to view my source I have to use the Jupyter Notebook software
Or copy my source directly from the .ipynb file which is messy and non-elegant
In the end I decided to use the Jupyter Notebooks as I could always revert if needed

On 2020.01.08.0831.EST I decided to re-manage it AGAIN!!!
No need for Jupyter Notebooks really, they aren't the most logical solution
Instead I can create an Euler python package and put all the logic there
Now it's significantly easier to manage, especially since all resources can be shared easily now

2020.02.27.2343.EST I've decided to get rid of old C/CPP code to favor Python entirely
This will take awhile to do as my CPP code has lots of helpers that need to be translated
However I note that the importance of Project Euler solutions is not to calculate it the 'fastest', but rather efficiently
Significantly more complex and optimized solutions may potentially be implemented in compiled code
However I do not see the need to find the most optimized and convoluted solutions to equations anymore
The elegance that python allows me outweighs the marginal efficiency afforded by C/CPP in my opinion
As this is a repository the old work won't be lost, but rather archived which is fine by me
This process, once complete, will simplify the file hierarchy and make solution finding much more elegant
I will be creating a 'Refactored Solutions' folder for all equations that have been effectively converted to python only
All subsequent solutions to an equation will be removed from master
