/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LATINIME_VER4_BIGRAM_LIST_POLICY_H
#define LATINIME_VER4_BIGRAM_LIST_POLICY_H

#include "defines.h"
#include "suggest/core/policy/dictionary_bigrams_structure_policy.h"

namespace latinime {

class BigramDictContent;
class TerminalPositionLookupTable;

class Ver4BigramListPolicy : public DictionaryBigramsStructurePolicy {
 public:
    Ver4BigramListPolicy(BigramDictContent *const bigramDictContent,
            const TerminalPositionLookupTable *const terminalPositionLookupTable)
            : mBigramDictContent(bigramDictContent),
              mTerminalPositionLookupTable(terminalPositionLookupTable) {}

    void getNextBigram(int *const outBigramPos, int *const outProbability,
            bool *const outHasNext, int *const bigramEntryPos) const;

    void skipAllBigrams(int *const pos) const {
        // Do nothing because we don't need to skip bigram lists in ver4 dictionaries.
    }

    bool addNewEntry(const int terminalId, const int newTargetTerminalId, const int newProbability,
            bool *const outAddedNewEntry);

 private:
    DISALLOW_IMPLICIT_CONSTRUCTORS(Ver4BigramListPolicy);

    int getEntryPosToUpdate(const int targetTerminalIdToFind, const int bigramListPos) const;

    BigramDictContent *const mBigramDictContent;
    const TerminalPositionLookupTable *const mTerminalPositionLookupTable;
};
} // namespace latinime
#endif /* LATINIME_VER4_BIGRAM_LIST_POLICY_H */
