testString = "LuaBridge works!"
number = 42


--[[ Fonction d'initialisation
 des données du joueur IA ]]--
function initData( ... )
player = {
    pos = {
         x = _x,
         y = _y,
    },
    alive = _alive
    range = _range,
-- you can also have comments
}
end



--[[ Fonction permettant
 de trouver une cible humaine ]]--
function findTarget( ... )
	-- body
end



--[[ Fonction qui fait appel à une methode cpp permettant
de déterminer si un mouvement est réalisable ]]--
function tryToMove( ... )
	-- body
end


function quitAndFree( ... )
	-- body
end