#ifndef ChordEvaluationStats_h
#define ChordEvaluationStats_h

//============================================================================
/**
	Class representing .

	@author		Johan Pauwels
	@date		20100921
*/
//============================================================================
#include <vector>
#include <Eigen/Core>
#include "MusOO/Chord.h"

class ChordEvaluationStats
{
public:

	/** Default constructor. */
	ChordEvaluationStats(const Eigen::ArrayXXd& inConfusionMatrix, const std::vector<MusOO::Chord> inChords, const Eigen::ArrayXXd::Index inNumOfChromas = 12);

	/** Destructor. */
	virtual ~ChordEvaluationStats();

	const double getCorrectChords() const;
	const double getCorrectNoChords() const;
	const double getChordDeletions() const;
	const double getChordInsertions() const;
	const double getChordSubstitutions() const;

	const double getOnlyRootCorrect() const;
	const double getOnlyTypeCorrect() const;
	const double getBothRootAndTypeWrong() const;

	const Eigen::ArrayXXd::Index getNumOfUniquesInRef() const;
	const Eigen::ArrayXXd::Index getNumOfUniquesInTest() const;

	const double getRefChordsDuration() const;
	const double getRefNoChordsDuration() const;
    
    const Eigen::ArrayXXd getCorrectChordsPerType() const;
    const double getChordsWithNWrong(const Eigen::ArrayXXd::Index inNumOfWrongChromas) const;
    const double getChordsWithSDI(const Eigen::ArrayXXd::Index inNumOfSubstitutedChromas, const Eigen::ArrayXXd::Index inNumOfDeletedChromas, const Eigen::ArrayXXd::Index inNumOfInsertedChromas) const;
    const double getChordsWithUnknownWrong() const;

protected:


private:

	const Eigen::ArrayXXd m_ConfusionMatrix;
	const Eigen::ArrayXXd::Index m_NumOfChromas;
	const Eigen::ArrayXXd::Index m_NumOfChordTypes;
	const Eigen::ArrayXXd::Index m_NumOfChords;

	Eigen::ArrayXd m_OnlyRoots;
	Eigen::ArrayXd m_OnlyTypes;
    const Eigen::ArrayXXd m_ChordsMatrix;
    
    const bool m_HasTestCatchAllChords;
    const bool m_HasRefNoChord;
    
    Eigen::ArrayXXi m_CardinalityDiff;
    Eigen::ArrayXXi m_NumOfWrongChromas;
};

#endif	// #ifndef ChordEvaluationStats_h
