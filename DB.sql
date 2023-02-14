-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  mar. 14 fév. 2023 à 12:24
-- Version du serveur :  10.4.10-MariaDB
-- Version de PHP :  7.4.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `bibliothèque`
--

-- --------------------------------------------------------

--
-- Structure de la table `adherent`
--

DROP TABLE IF EXISTS `adherent`;
CREATE TABLE IF NOT EXISTS `adherent` (
  `idAdht` int(11) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `prenom` varchar(100) NOT NULL,
  `statut` varchar(100) NOT NULL,
  PRIMARY KEY (`idAdht`),
  UNIQUE KEY `idAdht` (`idAdht`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `adherent`
--

INSERT INTO `adherent` (`idAdht`, `nom`, `prenom`, `statut`) VALUES
(1, 'OKA', 'Mira ', 'nouvelleAderent'),
(2, 'somaila', 'geoffroy', 'AdherehtCertifié'),
(3, 'doudou', 'nelly', 'AdherehtCertifié');

-- --------------------------------------------------------

--
-- Structure de la table `emprunt`
--

DROP TABLE IF EXISTS `emprunt`;
CREATE TABLE IF NOT EXISTS `emprunt` (
  `idEmprunt` int(10) UNSIGNED NOT NULL,
  `date_emprunt` date NOT NULL,
  `retourné` tinyint(1) NOT NULL,
  `idAdht` int(11) NOT NULL,
  `idLivre` int(11) NOT NULL,
  PRIMARY KEY (`idEmprunt`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `emprunt`
--

INSERT INTO `emprunt` (`idEmprunt`, `date_emprunt`, `retourné`, `idAdht`, `idLivre`) VALUES
(1, '2023-02-01', 0, 1, 3);

-- --------------------------------------------------------

--
-- Structure de la table `livres`
--

DROP TABLE IF EXISTS `livres`;
CREATE TABLE IF NOT EXISTS `livres` (
  `idLivre` int(11) NOT NULL,
  `Titre` varchar(100) NOT NULL,
  `Auteur` varchar(100) NOT NULL,
  PRIMARY KEY (`idLivre`),
  UNIQUE KEY `idLivre` (`idLivre`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `livres`
--

INSERT INTO `livres` (`idLivre`, `Titre`, `Auteur`) VALUES
(1, 'mamadou et bineta', 'sengor'),
(2, 'et pourtant elle pleurait', 'esai biton'),
(3, 'la jare persé', 'Coulibaly mariame'),
(4, 'l\'etranger', 'Albert camus');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
