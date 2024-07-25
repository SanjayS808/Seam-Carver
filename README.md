
Seam Carver PPM File Resizer

Overview
The Seam Carver PPM File Resizer is a powerful tool designed to intelligently resize PPM (Portable Pixmap) images by removing or inserting seams of pixels. This technique, known as content-aware image resizing, ensures that the most important features of the image are preserved while minimizing distortion.

Features
Seam Carving Algorithm: Utilizes dynamic programming to find and remove the least significant seams, ensuring the most important parts of the image are retained.
Supports PPM Format: Specifically designed to handle PPM files, a simple and widely-used image format.
Resize Options: Allows for both horizontal and vertical resizing.
Efficient Performance: Optimized to handle large images efficiently.

Installation
Clone the repository:
sh
Copy code
git clone https://github.com/yourusername/seam-carver-ppm.git
Navigate to the project directory:
sh
Copy code
cd seam-carver-ppm
Compile the source code:
sh
Copy code
make
Usage
Command Line
sh
Copy code
./seamcarver input.ppm output.ppm [options]
Options
-w <width>: Resize to the specified width.
-h <height>: Resize to the specified height.
Examples
Resize an image to a width of 300 pixels:
sh
Copy code
./seamcarver input.ppm output.ppm -w 300
Resize an image to a height of 200 pixels:
sh
Copy code
./seamcarver input.ppm output.ppm -h 200
How It Works
Energy Calculation: The energy of each pixel is calculated using the gradient magnitude. High-energy pixels represent important features, while low-energy pixels are less significant.
Seam Identification: Using dynamic programming, the algorithm identifies the seam (a connected path of pixels from top to bottom or left to right) with the lowest total energy.
Seam Removal/Insertion: The identified seam is removed (for shrinking) or duplicated (for enlarging), and the process repeats until the desired dimensions are achieved.
Example
Input Image

Output Image (Resized to 300x200)

Dependencies
Standard C++ libraries
Contributing
Fork the repository
Create a new branch (git checkout -b feature-branch)
Commit your changes (git commit -m 'Add some feature')
Push to the branch (git push origin feature-branch)
Create a new Pull Request
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Inspired by the work of Shai Avidan and Ariel Shamir on seam carving for content-aware image resizing.
Feel free to reach out if you have any questions or need further assistance!

Contact
Author: Sanjay Sugumar
Email: sanjaysugumar20@gmail.com
GitHub: SanjayS808
LinkedIn: sanjays20
Thank you for using the Seam Carver PPM File Resizer!
