function checkWord() {
    const word = document.getElementById('wordInput').value;
    if (word === "") {
        alert("Please enter a word!");
        return;
    }

    // Use Fetch API to communicate with the backend server
    fetch('/server.cgi', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: 'word=' + encodeURIComponent(word)
    })
        .then(response => response.text())
        .then(data => {
            document.getElementById('output').innerHTML = data;
        })
        .catch(error => {
            console.error('Error:', error);
        });
}
