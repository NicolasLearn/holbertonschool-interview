Slide 2 / Exemple de code vulnérable

# Récupère l'entrée utilisateur sans validation
nom_utilisateur = "Entrée utilisateur"
# La requête SQL est directement construite avec l'entrée utilisateur
requête = "SELECT * FROM utilisateurs WHERE nom = '" + nom_utilisateur + "';"
# Exécution de la requête potentiellement dangereuse sans protection
exécuter(requête)



Slide 2 / Exemple de code corrigé

# Récupère l'entrée utilisateur
nom_utilisateur = "Entrée utilisateur"
  # Utilisation d'une requête préparée avec un paramètre
requête = "SELECT * FROM utilisateurs WHERE nom = ?"
# Le paramètre utilisateur est traité séparément, empêchant toute injection malveillante
exécuter(requête, [nom_utilisateur])


Slide 2 / Exemple de Code malveillant

Input utilisateur : ' OR '1'='1'
Requête SQL : 
    SELECT * FROM utilisateurs WHERE nom = '' OR '1'='1';





Slide 3 / Exemple de code vulnérable

fonction verifier_utilisateur(nom, mot_de_passe):
# Vérification directe du mot de passe en clair, vulnérable aux attaques.
    si nom est dans base_de_donnees et mot_de_passe correspond:
        renvoyer "Connexion réussie"
    sinon:
        renvoyer "Échec"





Slide 3 / Exemple de code corrigé
fonction verifier_utilisateur(nom, mot_de_passe):
# Récupère le mot de passe haché et salé de la base de données
    hash_stocké = obtenir_hash(nom)
    # Comparaison sécurisée avec l'algorithme de hachage
    si vérifier_hachage(mot_de_passe, hash_stocké):
        renvoyer "Connexion réussie"
    sinon:
        renvoyer "Échec"






Slide 4 / Exemple de code vulnérableSlide
# Les données sont envoyées en clair sur une connexion non sécurisée
fonction envoyer_donnees(numero_carte):
    envoyer("http://site.com/paiement", numero_carte)






Slide 4 / Exemple de code corrigé
fonction envoyer_donnees(numero_carte):
# Les données sont chiffrées et transmises via HTTPS pour une sécurité renforcée
    envoyer("https://site.com/paiement", chiffrer(numero_carte))
