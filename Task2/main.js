//dropdown list function
var teams = [
  {teamName:"India",opponent:"Australia",winteam:"India won by 15 runs"},
  {teamName:"Australia",opponent:"India",winteam:"India won by 15 runs"},
  {teamName:"New Zealand",opponent:"Pakistan",winteam:"Pakistan won by 6 wickets"},
  {teamName:"Pakistan",opponent:"New Zealand",winteam:"Pakistan won by 6 wickets"}
]

var selectNode = document.getElementById('SelectTeam');
var opponentTeam = document.getElementById('oppTeam');
var winningTeam = document.getElementById('winTeam');

function displayTeamDetails(){
  var selected = selectNode.value;
  teams.forEach(function (team) {
    if (team.teamName === selected) {
      opponentTeam.textContent = [team.opponent];
      winningTeam.textContent = [team.winteam];
    }
  });
}

displayTeamDetails(); 

// Quotes of the day function
var prev = 0;

var quotes = [
  "The unexamined life is not worth living.@Socrates",
  "In the long run, the sharpest weapon of all is a kind and gentle spirit.@Anne Frank",
  "Don't cry because it's over, smile because it happened@Dr. Seuss",
  "Turn your wounds into wisdom.@Oprah Winfrey",
  "There are no regrets in life, just lessons.@Jennifer Aniston",
  "In the end, it's not the years in your life that count. It's the life in your years.@Abraham Lincoln",
  "I like criticism. It makes you strong.@LeBron James",
  "Life would be tragic if it weren’t funny.@Stephen Hawking",
  "Two things are infinite: the universe and human stupidity; and I'm not sure about the universe.@Albert Einstein",
  "Be who you are and say what you feel, because those who mind don't matter, and those who matter don't mind.@Bernard M. Baruch",
  "A room without books is like a body without a soul.@Marcus Tullius Cicero",
  "So many books, so little time.” @Frank Zappa",
  "Make each day your masterpiece.@John Wooden",
  "Nobody who ever gave his best regretted it.@George Halas",
  "Find people who will make you better.@Michelle Obama",
  "Life doesn’t require that we be the best, only that we try our best.@H. Jackson Brown Jr",
  "Do not dwell in the past, do not dream of the future, concentrate the mind on the present moment.@Buddha",
  "Life is a succession of lessons which must be lived to be understood.@Helen Keller",
  "Be the change that you wish to see in the world.@Mahatma Gandhi",
  "If you tell the truth, you don't have to remember anything.@Mark Twain",
  "The healthiest response to life is joy.@Deepak Chopra",
  "Keep calm and carry on.@ Winston Churchill",
  "The big lesson in life, baby, is never be scared of anyone or anything.@Frank Sinatra"
];

var quotedisplay = quotes[0].split("@");

  document.getElementById('quote').innerHTML =quotedisplay[0];
  document.getElementById('author').innerHTML = "--" + quotedisplay[1];

//generate new quotes on pressing quote button
function newQuote() {

var randomNumber=Math.floor(Math.random() * quotes.length);
  while(randomNumber == prev){
    randomNumber=Math.floor(Math.random() * quotes.length);
  }
  prev=randomNumber;
  var quotedisplay = quotes[randomNumber].split("@");

  document.getElementById('quote').innerHTML =quotedisplay[0];
  document.getElementById('author').innerHTML = "--" + quotedisplay[1];

}

//Combo key function

function keyCombos(e) {
  let evtobj = window.event ? event : e
  let t1 = document.getElementById('text1');
  let val = document.getElementById('text2');
  //key combo for shift+G
  if (evtobj.keyCode == 71 && evtobj.shiftKey) {
    e.preventDefault();
    val.value = t1.value;
  }
}

document.getElementById('text1').onkeydown = keyCombos;
