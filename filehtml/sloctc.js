let menuToggle = document.querySelector(".toggle");
let navigation = document.querySelector(".navigation");
let bangsangloc = document.querySelector(".bangsangloc");
menuToggle.onclick = function () {
    menuToggle.classList.toggle("active");
    navigation.classList.toggle("active");
    bangsangloc.classList.toggle("active");
};

// add active class in selected list item
let list = document.querySelectorAll(".list");
for (let i = 0; i < list.length; i++) {
    list[i].onclick = function () {
        let j = 0;
        while (j < list.length) {
            list[j++].className = "list";
        }
        list[i].className = "list active";
    };
}
document.querySelector(".sticks").addEventListener("click", (e) => {
    e.stopPropagation();
    e.preventDefault();
    //document.querySelector('.input').value = '';
    document.querySelector(".input-container").blur();
});

function myFunction(){
    location.href = 'http://www.hyperlinkcode.com/button-links.php'
    // mở tab mới 
    // window.open("http://www.hyperlinkcode.com/button-links.php");
    // window.focus();
}
    



