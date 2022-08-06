**Lets assume that we have p pigs which can give us the accurate result. Now we have
total Round of test = (timetoTest/TimetoDie) ie. T tests.
​
So for each T test there can be T+1  outcomes that is it can die in 1st or 2nd or Tth oit it means the T cases and the last case is it won't die! So total T+1 Outcomes are possible.
​
Now for each pig we have to go for T+1 outcomes i.e
(T+1)*(T+1)........*(T+1).
​
So T+1 tests rounds are there so for all p pigs the total combination will be (T+1) to the power p i.e (T+1)^p. Now this total combination should be greater than or equal to N.
​
Hence  the condition for the answer is going to be
(T+1)^p >= N
Taking log on both sides we will get the required answee
p >= log(N)/ log(T+1);
and hence ceil function is used in the return.****