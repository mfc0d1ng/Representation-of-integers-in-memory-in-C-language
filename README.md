# Representation of integers in memory
Have you ever wondered how integers are represented in your computer memory? the library provides a set of functions to get the representation of integers in your computer memory.

<h2> Requirements :- </h2>
This <a href="https://github.com/mfc0d1ng/Handling-dynamic-strings-in-C-language">library</a> is required for handling dynamic strings.

<br>
<h2> Examples </h2>

* Example A:

<pre>
<code class="language-c">
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include "include/to_bits.h"

int main()
{
    string bits = string_new();

    i32_to_bits(&bits, -1000);

    printf("Representation of (-1000) in memory is: %s\n", string_c_str(&bits));

    string_destructor(&bits);
    
    return EXIT_SUCCESS;
}
</code>
</pre>

* Example B:

<pre>
<code class="language-c">
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include "include/to_bits.h"

int main()
{
    string bits = string_new();

    i8_to_bits(&bits, -1);

    printf("Representation of (-1) in memory is: %s\n", string_c_str(&bits));

    string_destructor(&bits);
    
    return EXIT_SUCCESS;
}
</code>
</pre>


* Example C:

<pre>
<code class="language-c">
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;limits.h&gt;
#include "include/to_bits.h"

int main()
{
    string bits = string_new();

    u64_to_bits(&bits, ULLONG_MAX);

    printf("Representation of (ULLONG_MAX) in memory is: %s\n", string_c_str(&bits));

    string_destructor(&bits);
    
    return EXIT_SUCCESS;
}
</code>
</pre>

