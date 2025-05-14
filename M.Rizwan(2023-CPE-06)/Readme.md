<h1>Quiz Application in C++ (Timed Console Quiz)</h1>

<p>This is a <strong>console-based quiz application</strong> developed in <strong>C++</strong> that simulates a real-time quiz with a countdown timer for each question. It uses key C++ features like <strong>multithreading, atomic variables, mutex locks</strong>, and standard I/O operations.</p>

<h2>Key Features:</h2>
<ul>
    <li>Users get <strong>10 seconds</strong> per question to answer.</li>
    <li>Multithreaded:
        <ul>
            <li>One thread handles the countdown timer.</li>
            <li>Another listens for user input.</li>
        </ul>
    </li>
    <li>Automatic timeout if no input is given.</li>
    <li>Final score and percentage are calculated.</li>
    <li>Feedback based on performance.</li>
</ul>

<h2>Technologies Used:</h2>
<ul>
    <li><strong>C++ STL:</strong> vector, queue, thread, chrono, atomic, mutex</li>
    <li><strong>Threading:</strong> For simultaneous input and countdown handling</li>
    <li><strong>Formatted Output:</strong> Uses <code>&lt;iomanip&gt;</code> for displaying percentages</li>
</ul>

<h2>How it Works:</h2>
<ol>
    <li>Quiz starts after user confirmation.</li>
    <li>Each question displays 4 options with a 10-second timer.</li>
    <li>Correct answers increase the score.</li>
    <li>If time runs out or input is invalid, it's skipped.</li>
    <li>After all questions, percentage and result feedback are shown.</li>
</ol>

<h2>Use Case:</h2>
<p>Perfect for practicing <strong>real-time input handling</strong>, <strong>multithreading</strong>, and <strong>console-based quiz logic</strong> using C++.</p>

<h2>How to Run:</h2>
<pre><code>g++ -std=c++11 quiz.cpp -o quiz -pthread
./quiz
</code></pre>
