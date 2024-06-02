# How to contribute


## Getting Started

Before you can build the project, you'll need to set up your development environment. Here are the steps to get started:

1. **Install the required software:**

    This project requires CMake and a C++ compiler with C++20 standard supported. You can check what
    compiler has C++20 at [cppreference](https://en.cppreference.com/w/cpp/compiler_support/20).

    You can install these required tools on Ubuntu with the following command:

    ```sh
    sudo apt-get install cmake g++
    ```

    If you're using a different operating system, you'll need to install these tools in a way that's appropriate for your system.

2. **Clone the forked repository:**

    In order to send contributions, first you need to [Fork](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo) the repository on GitHub

    So, you can clone the repository with the following command:

    ```sh
    git clone https://github.com/<yourusername>/faker-cxx.git
    ```

    Replace `yourusername` with the correct values for this project.

3. **Get into a discussion:**

    Pick an issue from [issues](https://github.com/cieslarmichal/faker-cxx/issues) or you can refactor the code or implement features that you find useful.

## Making Changes

1. **Create a feature/bug branch from main branch:**

  ```sh
  git checkout -b feature/feature-name
  ```

  Please avoid working directly on the ``main`` branch.

2. **Follow the code style guide:**

    This project uses a `.clang-format` file to define its coding style. This file is automatically used by the `clang-format` tool to format code.

    The `.clang-format` file ensures that all code adheres to the project's coding style, providing consistency across the codebase. It includes settings for various formatting rules, such as indentation, spacing, and alignment.

    Before making changes, make sure you have `clang-format` installed. If you're using Visual Studio Code, you can install the `clang-format` extension.

    When you make a commit, `pre-commit` will automatically run `clang-format` on your code, ensuring it adheres to the project's coding style.

3. **Set up pre-commit hooks:**

    This project uses `pre-commit` hooks with `clang-format` to ensure code style consistency. Before making changes, set up the pre-commit hooks with the following commands:

    ```sh
    pip install pre-commit
    pre-commit install
    ```

    Now, `pre-commit` will automatically run `clang-format` on your code whenever you make a commit, ensuring it adheres to the project's coding style.

4. **Make commits of logical units:**

    This means that each commit should contain a complete and coherent piece of work that can be understood independently of other changes. For example, if you're fixing two different bugs, it's better to make two separate commits (one for each bug) rather than one commit that contains fixes for both bugs. This makes it easier to understand the purpose of each commit, and allows each change to be reviewed and applied separately.

5. **Make sure you have added the necessary tests for your changes:**

    If you're adding a new feature or changing existing functionality, it's important to update or add tests that verify your changes. This helps to ensure that your changes work as expected and don't introduce new bugs. It also helps other developers understand what your code is supposed to do.

6. **Run all the tests to assure nothing else was accidentally broken:**

    Before you submit your changes, you should run all of the project's tests to make sure your changes haven't inadvertently broken anything. Even if you think your changes are isolated, there could be unexpected interactions with other parts of the codebase.

7. **If you've added a new file to your project with non-Latin characters, ensure that the file encoding is set to Unicode (UTF-8 without signature) - Codepage 65001 in Microsoft Visual Studio Code:**

    If a file contains non-Latin characters (such as characters from Chinese, Arabic, or many other non-Latin alphabets), it's important to save the file with the correct encoding to ensure that the characters are displayed correctly. In Visual Studio Code, you can set the encoding for a file by clicking on the "UTF-8" button in the status bar at the bottom of the window, and then selecting "Save with Encoding" and choosing "UTF-8 without BOM".

## Building and Testing the Project

### Building the Project

To build the project, we use [CMake](https://cmake.org/getting-started/) with
[presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html).
This allows for a standardized and simplified build process across different environments.
Follow the steps below to build the project:

1. **Navigate to the project directory:**

    ```sh
    cd /path/to/faker-cxx
    ```

2. **Configure the build using the desired preset:**

    Presets are predefined sets of configuration options. This project has a preset for each compiler. To list the available presets, use the following command:

    ```sh
    cmake --list-presets
    "unixlike-gcc-debug"     - gcc Debug
    "unixlike-gcc-release"   - gcc Release
    "unixlike-clang-debug"   - clang Debug
    "unixlike-clang-release" - clang Release
    "windows-msvc-release"   - msvc Release
    "windows-msvc-release"   - msvc Debug
    ```


    For instance, if you are in Ubuntu and want to build using GCC in Debug mode, you should use the preset `unixlike-gcc-debug`. The `unixlike-clang-` preset should work for both Linux and macOS when using the CLang compiler.

    The `-S .` option in the following command specifies the source directory:

    ```sh
    cmake -S . --preset unixlike-gcc-debug
    ```
3. **Build the project:**

    The following command generates the build files and compiles the project using the settings specified in the `unixlike-gcc-debug` preset:


    ```sh
    cmake --build --preset unixlike-gcc-debug
    ```

### Testing the Project

After building the project, you can run the tests to ensure everything is working correctly. We use CTest for running tests. Follow the steps below to test the project:

**1. Run the tests using the same preset:**

    ```sh
    ctest --preset unixlike-gcc-debug
    ```

## Submitting Changes

Once you've made your changes and ensured they adhere to the project's coding style and pass all tests, you can submit them for review. Here's how:

1. **Push your changes:**

    First, you'll need to push your changes to the branch in your fork of the repository. You can do this with the following command:

    ```sh
    git push origin your-branch-name
    ```

    Replace `your-branch-name` with the name of the branch you created for your changes.

2. **Create a pull request:**

    After pushing your changes, you'll need to create a pull request. This is a way of proposing your changes to the project maintainers and allowing them to review your code.

    To create a pull request, go to the main page of the repository on GitHub, and click on the "Pull requests" tab. Then click on the "New pull request" button.

    In the "base" dropdown, select the main branch of the original repository, and in the "compare" dropdown, select the branch in your fork with your changes.

    Fill out the pull request form with a title and description that explain your changes, and then click "Create pull request".

    For more detailed instructions, see GitHub's guide on [creating a pull request from a fork](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork).

# Additional Resources

To assist you in contributing to the project, we've compiled a list of useful resources:

1. **Community Support:**

    If you have any questions or need help understanding a feature, feel free to join our [Discord Channel](https://discord.com/invite/h2ur8H6mK6). It's a great place to connect with other contributors and get answers to your questions.

2. **Reference Implementations:**

    If you're implementing a feature, you might find it helpful to look at [Faker.js](https://github.com/faker-js/faker). It's a similar project in JavaScript, and its implementations could serve as a useful reference.

3. **CMake and CTest Documentation:**

    If you're new to CMake and CTest, or if you need a refresher, check out their official documentation:

    - [CMake Documentation](https://cmake.org/cmake/help/latest/index.html)
    - [CTest Documentation](https://cmake.org/cmake/help/latest/manual/ctest.1.html)

Remember, the best way to learn is by doing. Don't be afraid to make mistakes and ask questions. We're here to help!
