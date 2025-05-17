# Plagiarism Checker in C++

## Introduction

This console application compares multiple text inputs to identify potential plagiarism by calculating the similarity percentage between documents. It uses the **Jaccard similarity** algorithm to compare the content based on word overlap after normalizing the text.

## Features

* Input multiple documents as plain text.
* Normalize text by:

  * Converting to lowercase.
  * Removing punctuation and extra spaces.
* Tokenize text into words for comparison.
* Calculate similarity percentage between pairs of documents.
* Supports up to 10 documents in a single comparison.

## Data Structures and Algorithms

* **Arrays**: Used to store words from each document.
* **String Manipulation**: Cleaning and splitting text into words.
* **Jaccard Similarity**: To calculate similarity between two sets of words.

## How to Run

1. Install Dev C++ with TDM-GCC 4.9.2 or any compatible C++ compiler.
2. Open the project in Dev C++.
3. Compile and run the program.
4. Enter the number of documents to compare.
5. Input the text for each document, ending with an empty line.
6. View the similarity percentage between each pair of documents.

## Example Output

```
Enter the number of documents to compare: 2

Enter text for document 1:
This is a sample text.
Another line here.

Enter text for document 2:
This is a sample text with a different ending.

Similarity between Document 1 and Document 2: 66.67%
```

## Limitations

* Does not support file input, only console input.
* Accuracy may vary with text structure and formatting differences.
* Works with plain text without advanced NLP techniques.

## Future Enhancements

* Support for file-based input.
* Improved similarity calculation using advanced algorithms.
* Enhanced text normalization, including stopword removal.

## License

This project is open-source and available under the MIT License.
