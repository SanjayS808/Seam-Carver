# Seam Carver PPM File Resizer

## Overview

The Seam Carver PPM File Resizer is a tool that uses seam carving to intelligently resize PPM (Portable Pixmap) images. This content-aware resizing technique removes or adds seams to minimize distortion while preserving important image features.

## Features

- **Seam Carving Algorithm:** Intelligent seam removal and insertion based on pixel significance.
- **PPM Format Support:** Handles PPM files efficiently.
- **Flexible Resizing:** Options for both horizontal and vertical resizing.
- **Performance:** Optimized for handling large images.

## Installation

1. **Clone the Repository:**

    ```sh
    git clone https://github.com/yourusername/seam-carver-ppm.git
    ```

2. **Navigate to the Project Directory:**

    ```sh
    cd seam-carver-ppm
    ```

3. **Compile the Source Code:**

    ```sh
    make
    ```

## Usage

### Command Line

Run the tool with the following command:

```sh
./seamcarver input.ppm output.ppm [options]
