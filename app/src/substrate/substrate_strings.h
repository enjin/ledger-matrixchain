/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Modules names
static const char* STR_MO_BALANCES = "Balances";

// Methods names
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_SET_BALANCE = "Force set balance";
static const char* STR_ME_UNLOCK = "Unlock";
static const char* STR_ME_EXECUTE = "Execute";
static const char* STR_ME_CLOSE = "Close";
static const char* STR_ME_SUBMIT = "Submit";
static const char* STR_ME_CANCEL = "Cancel";
static const char* STR_ME_KILL = "Kill";
static const char* STR_ME_SET_FEE = "Set fee";
static const char* STR_ME_SET_ACCOUNT_ID = "Set account id";
static const char* STR_ME_REPORT_AWESOME = "Report awesome";
static const char* STR_ME_RETRACT_TIP = "Retract tip";
static const char* STR_ME_TIP_NEW = "Tip new";
static const char* STR_ME_TIP = "Tip";
static const char* STR_ME_CLOSE_TIP = "Close tip";
static const char* STR_ME_SLASH_TIP = "Slash tip";
static const char* STR_ME_PUT_IN_FRONT_OF = "Put in front of";
static const char* STR_ME_JOIN = "Join";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_SET_STATE = "Set state";
static const char* STR_ME_SET_CONFIGS = "Set configs";
static const char* STR_ME_WITHDRAW = "Withdraw";
static const char* STR_ME_EDIT = "Edit";

// Items names
static const char* STR_IT_code = "Code";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT_subkeys = "Subkeys";
static const char* STR_IT_bytes = "Bytes";
static const char* STR_IT_hash = "Hash";
static const char* STR_IT_now = "Now";
static const char* STR_IT_index = "Index";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_freeze = "Freeze";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_old_reserved = "Old reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_min_commission = "Min commission";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_proposal = "Proposal";
static const char* STR_IT_ref_index = "Ref index";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_to = "To";
static const char* STR_IT_balance = "Balance";
static const char* STR_IT_target = "Target";
static const char* STR_IT_maybe_ref_index = "Maybe ref index";
static const char* STR_IT_prop_index = "Prop index";
static const char* STR_IT_owner = "Owner";
static const char* STR_IT_maybe_hash = "Maybe hash";
static const char* STR_IT_prime = "Prime";
static const char* STR_IT_old_count = "Old count";
static const char* STR_IT_length_bound = "Length bound";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_approve = "Approve";
static const char* STR_IT_remove = "Remove";
static const char* STR_IT_add = "Add";
static const char* STR_IT_members = "Members";
static const char* STR_IT_beneficiary = "Beneficiary";
static const char* STR_IT_proposal_id = "Proposal id";
static const char* STR_IT_poll_index = "Poll index";
static const char* STR_IT_class_ = "Class";
static const char* STR_IT_proposal_origin = "Proposal origin";
static const char* STR_IT_enactment_moment = "Enactment moment";
static const char* STR_IT_track = "Track";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_call_encoded_len = "Call encoded len";
static const char* STR_IT_call_weight_witness = "Call weight witness";
static const char* STR_IT_call = "Call";
static const char* STR_IT_ethereum_signature = "Ethereum signature";
static const char* STR_IT_vesting_schedule = "Vesting schedule";
static const char* STR_IT_statement = "Statement";
static const char* STR_IT_old = "Old";
static const char* STR_IT_maybe_preclaim = "Maybe preclaim";
static const char* STR_IT_schedule = "Schedule";
static const char* STR_IT_schedule1_index = "Schedule1 index";
static const char* STR_IT_schedule2_index = "Schedule2 index";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_as_origin = "As origin";
static const char* STR_IT_weight = "Weight";
static const char* STR_IT_account = "Account";
static const char* STR_IT_info = "Info";
static const char* STR_IT_subs = "Subs";
static const char* STR_IT_reg_index = "Reg index";
static const char* STR_IT_max_fee = "Max fee";
static const char* STR_IT_fee = "Fee";
static const char* STR_IT_fields = "Fields";
static const char* STR_IT_judgement = "Judgement";
static const char* STR_IT_identity = "Identity";
static const char* STR_IT_sub = "Sub";
static const char* STR_IT_data = "Data";
static const char* STR_IT_real = "Real";
static const char* STR_IT_delegate = "Delegate";
static const char* STR_IT_spawner = "Spawner";
static const char* STR_IT_height = "Height";
static const char* STR_IT_ext_index = "Ext index";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_timepoint = "Timepoint";
static const char* STR_IT_description = "Description";
static const char* STR_IT_bounty_id = "Bounty id";
static const char* STR_IT_curator = "Curator";
static const char* STR_IT_parent_bounty_id = "Parent bounty id";
static const char* STR_IT_child_bounty_id = "Child bounty id";
static const char* STR_IT_reason = "Reason";
static const char* STR_IT_tip_value = "Tip value";
static const char* STR_IT_dislocated = "Dislocated";
static const char* STR_IT_lighter = "Lighter";
static const char* STR_IT_pool_id = "Pool id";
static const char* STR_IT_extra = "Extra";
static const char* STR_IT_member_account = "Member account";
static const char* STR_IT_unbonding_points = "Unbonding points";
static const char* STR_IT_root = "Root";
static const char* STR_IT_state = "State";
static const char* STR_IT_metadata = "Metadata";
static const char* STR_IT_new_root = "New root";
static const char* STR_IT_new_nominator = "New nominator";
static const char* STR_IT_new_bouncer = "New bouncer";
static const char* STR_IT_member = "Member";
static const char* STR_IT_permission = "Permission";
static const char* STR_IT_other = "Other";
static const char* STR_IT_new_commission = "New commission";
static const char* STR_IT_max_commission = "Max commission";
static const char* STR_IT_change_rate = "Change rate";
static const char* STR_IT_eras_to_check = "Eras to check";
static const char* STR_IT_up_to = "Up to";
static const char* STR_IT_weight_limit = "Weight limit";
static const char* STR_IT_duration = "Duration";
static const char* STR_IT_cap = "Cap";
static const char* STR_IT_first_period = "First period";
static const char* STR_IT_last_period = "Last period";
static const char* STR_IT_end = "End";
static const char* STR_IT_verifier = "Verifier";
static const char* STR_IT_signature = "Signature";
static const char* STR_IT_memo = "Memo";
static const char* STR_IT_message = "Message";
static const char* STR_IT_assets = "Assets";
static const char* STR_IT_fee_asset_item = "Fee asset item";
static const char* STR_IT_location = "Location";
static const char* STR_IT_suspended = "Suspended";

#ifdef __cplusplus
}
#endif
