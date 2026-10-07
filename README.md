In a quest to learn C++, I had this idea of going for 50 consecutive days learning C++

Well, in as much as I did not do it for 50 consecutive days due to school and some days feeling off, I made sure
to keep pushing starting from day 0 (like a true programmer) to day 50 (I know those are 51 days I just added an extra coz 49 feels odd)

I also built some projects as I thought it was a better idea to put the skills into practice

Here are some of the few things I worked on:

1. A simple [pong game](https://github.com/martxrrr/cpp-maxxing/tree/main/day25) using SFML 3 as the graphics library
<br>

2. A [library system simulator](https://github.com/martxrrr/cpp-maxxing/tree/main/day30) with actual record keeping in local storage in json format using the **nlohmann json** library
<br>

3. A [snake game](https://github.com/martxrrr/cpp-maxxing/tree/main/day28) in SFML 3
	Just recreating the infamous snake game
<br>

4. [Duplicate file finder](https://github.com/martxrrr/cpp-maxxing/tree/main/day27)
   A simple tool that helps me check for duplicate files in the system and deletes them to free up space
   It uses SHA256 hashing algorithm from openSSL for fingerprinting.
<br>

5. An command line [encryption tool](https://github.com/martxrrr/cpp-maxxing/tree/main/day50)
	A tool that takes in a directory and a password to loop through the directory recursively and encrypts every file
	and replaces them with a decrypted version. It also decrypts a file with the help of a password.
	The tool uses **Crypto++** library (SHA256 for hashing of password and AES for encryption)

Tested and Developed on Arch Linux