class NotFormatJson extends Error {
    constructor(message) {
        super(message);
        this.name = "NotFormatJson";
    }
}

let isJson = (text) => {
    try {
        let test = JSON.parse(text)

        if (typeof test != 'object') {
            throw new NotFormatJson('O texto não é um JSON')
        } else {
            alert('O texto é um JSON')
        }
    } catch (error) {
        alert(error)
    }
}

isJson('aaa{"name": "John", "age": 30, "city": "New York"}')